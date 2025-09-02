
User need to load the .py by running python load using keyins dialog box.
mdl load ustnpython
python load ECCrud.py

pyeccrud consist of following functions:

    Locating and loading the schema from the directory.
    Attach ECInstances with properties to created line elements and create relationship between ECInstances.
    Read properties of instances and relationship between them.
    Update instance properties.
    Delete instances and relationship.


Following are the KeyIns - 
    
pyeccrud importschema			:    This keyin is used to locate schema and import it to dgn file.
pyeccrud createinstancesandrelations    :    This keyin creates two lines and attach both gadget and widget instances to separate line and create relationship between them.
pyeccrud readinstancesandrelations      :    This keyin reads the properties of gadget, widget instances.
pyeccrud updateinstancesandrelations 	:    This keyin is used to update the gadget, widget instances.
pyeccrud deleteinstancesandrelations    :    This keyin is used to delete the gadget, widget instances and relations.