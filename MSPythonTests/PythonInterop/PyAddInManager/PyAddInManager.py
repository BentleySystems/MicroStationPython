from tkinter import *
from tkinter import filedialog
import os

root = Tk()
root.geometry("450x600")
root.title("Python AddIn Manager")

# Create Frame widget
frame = Frame(root)
frame.pack(expand=True, fill=BOTH)

left_frame = Frame(frame, padx=5, pady=5)
left_frame.pack(side=LEFT, fill=BOTH, expand= True )


right_frame = Frame(frame, padx=5, pady=5)
right_frame.pack(fill=BOTH)

addInList = Listbox(left_frame, selectmode=SINGLE)
addInList.pack(expand=True, fill=BOTH)

def addAddin():
    script = filedialog.askopenfilename(title='select file', filetypes=(("Python Files", ".py"),))
    if script not in addInList.get(0, END):
        addInList.insert(END, script)
        addInList.selection_clear(0, 'end')
        addInList.select_set('end')


def runScript():
    script = addInList.get(ACTIVE)
    if len(script) == 0:
        return
    if os.path.exists(script):
        exec(open(script).read())


addBtn = Button(right_frame, text='Add', width=10, command=addAddin)
addBtn.pack (pady=10)

runBtn = Button(right_frame, text='Run', width=10, command=runScript)

runBtn.pack(pady=10)

root.mainloop()