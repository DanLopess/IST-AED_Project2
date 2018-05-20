void calculateLateStart(List x){
	link i,f;
	for(i = x->head; i != NULL; i=i->next){
		if(!isDependency(x,((Item)i->item)->id)){ /*If it is a final task*/
			((Item)i->item)->late = ((Item)i->item)->early;
			for(f = ((Item)i->item)->dependencies->head; f!=NULL;f=f->next){

			}
		}
	}
}
