
typedef unsigned long int ulInt;

Task readTask(){ /*Reads a certain task without dependencies*/
	char c;
	Task task = (Task)malloc(sizeof(struct task));

	scanf("%lu", &task->id);
	if(nonExistant(task->id)){ /*nonExistant MUST be from hashTable*/
		/*ADD HERE - id to hashtable*/
		while((c=getchar())==' ');
		if (c == '\"')
			scanf ("%[^\"]%*c", task->description); /*reads descrp with spaces until " */
		scanf("%lu", &task->duration);
	}
	else{
		printf("id already exists");
		free(task);
		return NULL;
	}
}

void addTask(Task task, List x){
	link node;
	ulInt tempId;
	task->dependencies = (List) malloc(sizeof(struct list));
	/*---------------------Taking care of dependencies---------------------*/
	while(scanf("%lu", tempId[0]) == 1){
		if(!nonExistant(tempId)){
			printf("no such task\n");
			deleteList(task->dependencies);
			free(tempId);
			free(task);
			return;
		}
		free(tempId);
		addNode(task->dependencies,newNode(tempId, NULL));
	}
	/*---------------------------------------------------------------------*/
	free(tempId);
	node = newNode(task,NULL);
	addNode(x,node)
}

int nonExistant(List x, unsigned long int id){
	link i;
	for(i = x->head; i != NULL; i = i->next)
		if(i->item.id == id)
			return 0;
	return 1;

}

/*cada tarefa ira ter lista de ids das dependentes
quando remover um node, remover tambem das dependentes das outras tasks*/
