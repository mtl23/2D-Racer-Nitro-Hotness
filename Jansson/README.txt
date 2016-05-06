So heres the basic layout of a JSON file.
{} represents and object
[] represents an array
{"Object" :

[
	{	
		"An array of objects":"Value",
		"plant":"Rose",
		"Food": "Rice and beans",
		"Game" :"Farcry"
	},
	{
	"2nd object in the array" : second value
 	"plant":"Rose",
	"Food": "Rice and beans",
	"Game" :"Farcry"
	"Number" : 1
	}
]

}


SO here i have an object named object that contains an array of objects.
JSON Uses key value pairs so plant is a key and "rose" is its value. The value doesnt 
have to be a string it can be a number. Now parsing through a JSON file using 
jansson might be a little confusing at first. So ive provided sample code. Documentation can be found
on there website
	
	json_t *root;
	json_error_t err;
	root = json_load_file("README.json",0,&err);
	if(!root)
	{
		fprintf(stderr,"error: on line %d : %s\n", err.line,err.text);
		exit(1);
	}

		json_t *data , *obj; 
		int frameW, frameH;
		data = json_object_get(root,"Object");
			// check to see if its an object
			if(!json_is_array(data))
			{
				fprintf(stderr, "error: commit %d: Not an array\n", 0);
				json_decref(root);
				exit(1);
			}
		//if so loop through it
		for(int i = 0;i < json_array_size(data);++i)
		{
			obj = json_array_get(data,i);	
			\\gets the numeric value associated with the key
			int number = json_number_value(json_object_get(obj,"number"));
		}
		\\ close when done
		json_decref(root);