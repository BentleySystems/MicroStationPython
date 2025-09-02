#---------------------------------------------------------------------------------------------
#  Copyright (c) Bentley Systems, Incorporated. All rights reserved.
#  See LICENSE.md in the repository root for full copyright notice.
#---------------------------------------------------------------------------------------------
import os
import tkinter as tk
import sys
import re
from code import InteractiveConsole
from contextlib import redirect_stderr, redirect_stdout
from io import StringIO

from MSPyBentley import *
from MSPyBentleyGeom import *
from MSPyECObjects import *
from MSPyDgnPlatform import *
from MSPyDgnView import *
from MSPyMstnPlatform import *


'''
Sample demonstrating how to run a Python terminal in MicroStation
'''

s_winDestroy = False
s_root = tk.Tk()

def on_closing ():
    """
    Handles the closing event of the terminal window.

    This function sets the global variable `s_winDestroy` to True and 
    destroys the root window `s_root`.

    Globals:
        s_winDestroy (bool): A flag indicating whether the window has been destroyed.
        s_root (Tk): The root window of the terminal.
    """
    global s_winDestroy
    global s_root
    s_root.destroy()
    s_winDestroy = True

class History(list):
    def __getitem__(self, index):
        """
        Retrieve an item from the list at the specified index.

        :param index: The index of the item to retrieve.
        :type index: int
        
        :return: The item at the specified index, or None if the index is out of range.
        :rtype: Any
        
        :raises IndexError: If the index is out of range.
        """
        try:
            return list.__getitem__(self, index)
        except IndexError:
            return


class TextConsole(tk.Text):
    def __init__(self, master, **kw):
        """
        Initialize the Terminal widget.
        :param master: The parent widget.
        :type master: tkinter.Widget
        :param kw: Additional keyword arguments for configuring the Text widget.
        :keyword width: The width of the terminal (default is 150).
        :keyword wrap: The wrap mode of the text (default is 'word').
        :keyword prompt1: The primary prompt string (default is '>>> ').
        :keyword prompt2: The secondary prompt string (default is '... ').
        :keyword banner: The banner text displayed at the start (default is 'Python <version>\n').
        :ivar history: An instance of the History class to manage command history.
        :ivar _hist_item: The current history item index.
        :ivar _hist_match: The current history match string.
        :ivar _console: An instance of InteractiveConsole to execute commands.
        :ivar _prompt1: The primary prompt string.
        :ivar _prompt2: The secondary prompt string.
        """
        kw.setdefault('width', 150)
        kw.setdefault('wrap', 'word')
        kw.setdefault('prompt1', '>>> ')
        kw.setdefault('prompt2', '... ')
        banner = kw.pop('banner', 'Python %s\n' % sys.version)
        self._prompt1 = kw.pop('prompt1')
        self._prompt2 = kw.pop('prompt2')
        tk.Text.__init__(self, master, **kw)
        # --- history
        self.history = History()
        self._hist_item = 0
        self._hist_match = ''

        # --- initialization
        self._console = InteractiveConsole() # python console to execute commands
        self.insert('end', banner, 'banner')
        self.prompt()
        self.mark_set('input', 'insert')
        self.mark_gravity('input', 'left')

        # --- bindings
        self.bind('<Control-Return>', self.on_ctrl_return)
        self.bind('<Shift-Return>', self.on_shift_return)
        self.bind('<KeyPress>', self.on_key_press)
        self.bind('<KeyRelease>', self.on_key_release)
        self.bind('<Tab>', self.on_tab)
        self.bind('<Down>', self.on_down)
        self.bind('<Up>', self.on_up)
        self.bind('<Return>', self.on_return)
        self.bind('<BackSpace>', self.on_backspace)
        self.bind('<Control-c>', self.on_ctrl_c)
        self.bind('<Control-d>', self.on_ctrl_d)
        self.bind('<<Paste>>', self.on_paste)

    def on_ctrl_c(self, event):
        """
        Handle the Ctrl+C event to copy selected code to the clipboard, removing prompts first.

        :param event: The event object associated with the Ctrl+C action.
        :type event: Event

        This method processes the selected text in the terminal, removes any leading prompt characters,
        and then copies the cleaned text to the clipboard. The method identifies the prompts using
        `self._prompt1` and `self._prompt2` attributes.

        :return: Returns 'break' to indicate that the event has been handled.
        :rtype: str
        """
        sel = self.tag_ranges('sel')
        if sel:
            txt = self.get('sel.first', 'sel.last').splitlines()
            lines = []
            for i, line in enumerate(txt):
                if line.startswith(self._prompt1):
                    lines.append(line[len(self._prompt1):])
                elif line.startswith(self._prompt2):
                    lines.append(line[len(self._prompt2):])
                else:
                    lines.append(line)
            self.clipboard_clear()
            self.clipboard_append('\n'.join(lines))
        return 'break'
    
    def on_ctrl_d(self, event=None):
        """Handle Ctrl+d key press"""
        on_closing()
        return 'break'

    def on_paste(self, event):
        """
        Handle the paste event in the terminal.

        This method is triggered when a paste action is performed. It checks if the 
        current cursor position is before the 'input' mark and, if so, prevents the 
        paste action. If there is a selected text, it deletes the selection before 
        pasting the clipboard content at the current cursor position. After inserting 
        the clipboard content, it updates the command input.

        :param event: The event object associated with the paste action.
        :type event: Event
        
        :return: A string indicating whether to break the default event handling.
        :rtype: str
        """
        if self.compare('insert', '<', 'input'):
            return "break"
        sel = self.tag_ranges('sel')
        if sel:
            self.delete('sel.first', 'sel.last')
        txt = self.clipboard_get()
        self.insert("insert", txt)
        self.insert_cmd(self.get("input", "end"))
        return 'break'

    def prompt(self, result=False):
        """
        Display a prompt in the terminal.

        This method inserts a prompt string at the end of the terminal's text widget.
        Depending on the value of the `result` parameter, it will insert either `_prompt1` or `_prompt2`.

        :param result: If True, insert `_prompt2`. Otherwise, insert `_prompt1`. Defaults to False.
        :type result: bool
        """
        if result:
            self.insert('end', self._prompt2, 'prompt')
        else:
            self.insert('end', self._prompt1, 'prompt')
        self.mark_set('input', 'end-1c')

    def on_key_press(self, event):
        """
        Handle key press events in the terminal.

        This method processes key press events and performs actions based on the 
        current cursor position and the key pressed. If the cursor is before the 
        'input' mark and the key pressed is not 'Left' or 'Right', it moves the 
        cursor to the end of the input line. If the key pressed is not an 
        alphanumeric character, the event is ignored.

        :param event: The key press event containing information about the key 
                      pressed.
        :type event: Event
        
        :return: 'break' if the key pressed is not alphanumeric, otherwise None.
        :rtype: str or None
        """
        if self.compare('insert', '<', 'input') and event.keysym not in ['Left', 'Right']:
            self._hist_item = len(self.history)
            self.mark_set('insert', 'input lineend')
            if not event.char.isalnum():
                return 'break'

    def on_key_release(self, event):
        """
        Handle key release events to reset history scrolling.

        This method is triggered when a key is released. It checks if the current 
        cursor position is before the 'input' mark and if the released key is not 
        one of the arrow keys ('Left', 'Right'). If both conditions are met, it 
        resets the history item index to the length of the history.

        :param event: The event object containing information about the key release.
        :type event: Event
        
        :return: 'break' if the conditions are met to stop further event processing.
        :rtype: str or None
        """
        if self.compare('insert', '<', 'input') and event.keysym not in ['Left', 'Right']:
            self._hist_item = len(self.history)
            return 'break'

    def on_up(self, event):
        """
        Handle the up arrow key press event.

        This method is triggered when the up arrow key is pressed. It performs the following actions:
        
        - If the cursor is before the 'input' mark, it moves the cursor to the end and breaks the operation.
        - If the cursor is at the start of the input line, it navigates through the command history.
        - It matches the current input line with the history items and updates the input with the matched history item if found.

        :param event: The event object associated with the key press.
        :type event: Event
        
        :return: 'break' to indicate that the event has been handled.
        :rtype: str
        """
        if self.compare('insert', '<', 'input'):
            self.mark_set('insert', 'end')
            return 'break'
        elif self.index('input linestart') == self.index('insert linestart'):
            # navigate history
            line = self.get('input', 'insert')
            self._hist_match = line
            hist_item = self._hist_item
            self._hist_item -= 1
            item = self.history[self._hist_item]
            while self._hist_item >= 0 and not item.startswith(line):
                self._hist_item -= 1
                item = self.history[self._hist_item]
            if self._hist_item >= 0:
                index = self.index('insert')
                self.insert_cmd(item)
                self.mark_set('insert', index)
            else:
                self._hist_item = hist_item
            return 'break'

    def on_down(self, event):
        """
        Handle down arrow key press event.

        This method is triggered when the down arrow key is pressed. It performs the following actions:
        
        - If the cursor is before the 'input' mark, it moves the cursor to the end and breaks the event handling.
        - If the cursor is at the end of the line, it navigates through the command history to find a matching item.
          - If a matching item is found, it inserts the command and sets the cursor position.
          - If no matching item is found, it resets the history index and clears the input, inserting the current line.

        :param event: The event object associated with the key press.
        :type event: Event
        
        :return: 'break' to indicate that the event has been handled.
        :rtype: str
        """
        if self.compare('insert', '<', 'input'):
            self.mark_set('insert', 'end')
            return 'break'
        elif self.compare('insert lineend', '==', 'end-1c'):
            # navigate history
            line = self._hist_match
            self._hist_item += 1
            item = self.history[self._hist_item]
            while item is not None and not item.startswith(line):
                self._hist_item += 1
                item = self.history[self._hist_item]
            if item is not None:
                self.insert_cmd(item)
                self.mark_set('insert', 'input+%ic' % len(self._hist_match))
            else:
                self._hist_item = len(self.history)
                self.delete('input', 'end')
                self.insert('insert', line)
            return 'break'

    def on_tab(self, event):
        """
        Handle tab key press event.

        This method is triggered when the tab key is pressed. It performs different actions based on the current cursor position and selection:
        
        - If the cursor is before the 'input' mark, it moves the cursor to the end of the 'input' line.
        - If there is a text selection, it indents each selected line by inserting four spaces at the beginning.
        - If there is no selection and the character before the cursor is not alphanumeric or a period, it inserts four spaces at the cursor position.

        :param event: The event object associated with the tab key press.
        :type event: Event
        
        :return: A string "break" to indicate that the event has been handled.
        :rtype: str
        """
        if self.compare('insert', '<', 'input'):
            self.mark_set('insert', 'input lineend')
            return "break"
        # indent code
        sel = self.tag_ranges('sel')
        if sel:
            start = str(self.index('sel.first'))
            end = str(self.index('sel.last'))
            start_line = int(start.split('.')[0])
            end_line = int(end.split('.')[0]) + 1
            for line in range(start_line, end_line):
                self.insert('%i.0' % line, '    ')
        else:
            txt = self.get('insert-1c')
            if not txt.isalnum() and txt != '.':
                self.insert('insert', '    ')
        return "break"

    def on_shift_return(self, event):
        """
        Handle Shift+Return key press event.

        This method is triggered when the Shift+Return keys are pressed. It checks the 
        position of the cursor and either moves the cursor to the end of the input line 
        or executes the current commands.

        :param event: The event object containing information about the key press event.
        :type event: Event
        
        :return: 'break' if the cursor is moved to the end of the input line, otherwise None.
        :rtype: str or None
        """
        if self.compare('insert', '<', 'input'):
            self.mark_set('insert', 'input lineend')
            return 'break'
        else: # execute commands
            self.mark_set('insert', 'end')
            self.insert('insert', '\n')
            self.insert('insert', self._prompt2, 'prompt')
            self.eval_current(True)

    def on_return(self, event=None):
        """
        Handle Return key press.

        This method is triggered when the Return (Enter) key is pressed. It performs
        different actions based on the current cursor position relative to the 'input' mark.

        :param event: The event object associated with the key press, defaults to None.
        :type event: Event, optional
        
        :return: Always returns 'break' to indicate that the event has been handled.
        :rtype: str
        """
        if self.compare('insert', '<', 'input'):
            self.mark_set('insert', 'input lineend')
            return 'break'
        else:
            if self.eval_current(True) == False:
                return 'break'
            self.see('end')
        return 'break'

    def on_ctrl_return(self, event=None):
        """
        Handle the Ctrl+Return key press event.

        This method inserts a new line followed by a secondary prompt 
        at the current cursor position in the terminal.

        :param event: The event object associated with the key press, defaults to None.
        :type event: optional
        
        :return: A string 'break' to indicate that the event has been handled.
        :rtype: str
        """
        self.insert('insert', '\n' + self._prompt2, 'prompt')
        return 'break'

    def on_backspace(self, event):
        """
        Handle the backspace key press event.

        This method processes the backspace key press to delete characters
        or selected text in a text widget. It ensures that the cursor does
        not move before the 'input' mark and handles deletion of spaces
        according to indentation rules.

        :param event: The event object associated with the backspace key press.
        :type event: Event
        
        :returns: A string 'break' to indicate that the event has been handled.
        :rtype: str
        """
        if self.compare('insert', '<=', 'input'):
            self.mark_set('insert', 'input lineend')
            return 'break'
        sel = self.tag_ranges('sel')
        if sel:
            self.delete('sel.first', 'sel.last')
        else:
            linestart = self.get('insert linestart', 'insert')
            if re.search(r'    $', linestart):
                self.delete('insert-4c', 'insert')
            else:
                self.delete('insert-1c')
        return 'break'

    def insert_cmd(self, cmd):
        """
        Insert lines of code into the terminal, adding prompts.

        :param cmd: The command string to be inserted, which can contain multiple lines.
        :type cmd: str
        """
        input_index = self.index('input')
        self.delete('input', 'end')
        lines = cmd.splitlines()
        if lines:
            indent = len(re.search(r'^( )*', lines[0]).group())
            self.insert('insert', lines[0][indent:])
            for line in lines[1:]:
                line = line[indent:]
                self.insert('insert', '\n')
                self.prompt(True)
                self.insert('insert', line)
                self.mark_set('input', input_index)
        self.see('end')

    def eval_current(self, auto_indent=False):
        """
        Evaluate the current code in the terminal.

        :param auto_indent: If True, automatically indent the next line based on the previous line, defaults to False
        :type auto_indent: bool, optional
        
        :return: None
        :rtype: NoneType

        This method retrieves the current input from the terminal, processes it, and executes it in an interactive console.
        It handles multi-line commands, redirects stdout and stderr, and displays the output or errors in the terminal.
        If the command is incomplete, it waits for the rest of the code. It also manages command history and auto-indentation.
        """
        index = self.index('input')
        lines = self.get('input', 'insert lineend').splitlines() # commands to execute
        self.mark_set('insert', 'insert lineend')
        if lines:  # there is code to execute
            # remove prompts
            lines = [lines[0].rstrip()] + [line[len(self._prompt2):].rstrip() for line in lines[1:]]
            for i, l in enumerate(lines):
                if l.endswith('?'):
                    lines[i] = 'help(%s)' % l[:-1]
            cmds = '\n'.join(lines)
            self.insert('insert', '\n')
            # Check if the command is quit(). If so then close the shell.
            if "quit()" == cmds:
                on_closing()
                return False
            out = StringIO()  # command output
            err = StringIO()  # command error traceback
            with redirect_stderr(err):     # redirect error traceback to err
                with redirect_stdout(out): # redirect command output
                    # execute commands in interactive console
                    res = self._console.push(cmds)
                    # if res is True, this is a partial command, e.g. 'def test():' and we need to wait for the rest of the code
            errors = err.getvalue()
            if errors:  # there were errors during the execution
                self.insert('end', errors)  # display the traceback
                self.mark_set('input', 'end')
                self.see('end')
                self.prompt() # insert new prompt
            else:
                output = out.getvalue()  # get output
                if output:
                    self.insert('end', output, 'output')
                self.mark_set('input', 'end')
                self.see('end')
                if not res and self.compare('insert linestart', '>', 'insert'):
                    self.insert('insert', '\n')
                self.prompt(res)
                if auto_indent and lines:
                    # insert indentation similar to previous lines
                    indent = re.search(r'^( )*', lines[-1]).group()
                    line = lines[-1].strip()
                    if line and line[-1] == ':':
                        indent = indent + '    '
                    if line == "quit()":
                        on_closing()
                    self.insert('insert', indent)
                self.see('end')
                if res:
                    self.mark_set('input', index)
                    self._console.resetbuffer()  # clear buffer since the whole command will be retrieved from the text widget
                elif lines:
                    self.history.extend(lines)  # add commands to history
                    self._hist_item = len(self.history)
            out.close()
            err.close()
        else:
            self.insert('insert', '\n')
            self.prompt()

def main ():  # Define a function called "main"
    """
    Main function to initialize and run the Microstation Python Shell.

    This function sets up the main window for the Microstation Python Shell,
    creates an instance of the TextConsole class, and starts the main event loop.
    It also registers a callback function for the window close event.

    Global Variables:
    -----------------
    s_winDestroy : bool
        A flag to control the termination of the main event loop.
    s_root : tkinter.Tk
        The root window of the application.

    Notes:
    ------
    The function runs an infinite loop that updates the root window and processes
    the Python main event loop until `s_winDestroy` is set to True.
    """
    global s_winDestroy  # Declare two global variables
    global s_root
    console = TextConsole(s_root)  # Create an instance of TextConsole class
    console.pack(fill='both', expand=True)  # Set the packing options for the text console
    s_root.protocol("WM_DELETE_WINDOW", on_closing)  # Register a callback function for window close event
    s_root.title('Microstation Python Shell')  # Set the title of the root window
    while s_winDestroy == False :  # Start an infinite loop as long as s_winDestroy is False
        s_root.update ()  # Update the root window to reflect any changes
        PyCadInputQueue.PythonMainLoop()  # Run the main event loop for Python

if __name__ == '__main__':
    main ()

