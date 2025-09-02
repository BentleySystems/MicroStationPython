TextExample demonstrates creating multi-line/multi-format text using
MicroStation TextBlock API.

Note that this example does not try to create a generic editor. It just creates a
fixed TextBlock with different paragraphs, lines and runs using different TextBlock
properties, Paragraph properties and Run properties.

The example also demonstrates how to create Text Styles.

Here are the key-ins provided by this example.

TEXTEXAMPLE CREATETEXTSTYLES                 : Creates four text styles with different properties.
TEXTEXAMPLE CREATETEXT EXAMPLE1 NORMAL       : Creates normal text (Non-Vertical, Non-UpsideDown, Non-Backwards).
TEXTEXAMPLE CREATETEXT EXAMPLE1 VERTICAL     : Creates vertical text.
TEXTEXAMPLE CREATETEXT EXAMPLE1 UPSIDEDOWN   : Creates upsidedown text.
TEXTEXAMPLE CREATETEXT EXAMPLE1 BACKWARDS    : Creates Backwards text.
TEXTEXAMPLE CREATETEXT EXAMPLE2              : Creates Normal Text by direct calls to TextBlock API. This example also demonstrates the use of stacked fractions.

