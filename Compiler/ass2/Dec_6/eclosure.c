#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* NFA is represented as a graph with 
 * states being the nodes and 
 * transitions the labled edges
 */

struct node;

typedef struct {
	char lable;
	struct node * dest;
} edge;

typedef struct node{
	char * name;
	int nedges;
	edge * edges[100];
	int isvisited;
} node;

typedef struct {
	node * nodes[100];
	int nnodes;
} graph;

node * createNode(char * name){
	node * newNode = (node *)calloc(1, sizeof(node));
	char * nodename = (char * )malloc(strlen(name) + 1);
	strcpy(nodename, name);
	newNode->name = nodename;
	newNode->nedges = 0;
	newNode->isvisited = 0;
	return newNode;
}

void addEdge(char lable, node * source, node * dest) {
	edge * newEdge = (edge *)calloc(1, sizeof(edge));
	newEdge->lable = lable;
	newEdge->dest = dest;
	source->edges[source->nedges] = newEdge;
	source->nedges++; 		/* TODO: check if there is space for the edge */
}

graph * createGraph(){
	graph * newGraph = (graph *)calloc(1, sizeof(graph));
	newGraph->nnodes = 0;
	return newGraph;
}

void addNode(graph * g, node * node){
	g->nodes[g->nnodes] = node;
	g->nnodes++;
}

node * getNodeWithName(graph * g, char * name){
	/* do a linear search */
	char * nodename;
	int nnodes = g->nnodes;
	for (int iii = 0; iii < nnodes; ++iii){
		nodename = g->nodes[iii]->name;
		if(strcmp(nodename, name) == 0){
			return g->nodes[iii];
		}
	}
	return NULL;
}

void printGraph(graph * g){
	int nnodes = g->nnodes;
	int nedges, iii, jjj;
	node * n;
	edge * e;
	for(iii = 0; iii < nnodes; iii++){
		n = g->nodes[iii];
		printf("[%s] => ", n->name);
		nedges = n->nedges;
		for(jjj = 0; jjj < nedges; jjj++){
			e = n->edges[jjj];
			printf("(%c, %s)", e->lable, e->dest->name);
		}
		puts("");
	}
}

void clearVisits(graph * g){
	int nnodes = g->nnodes;
	for(int iii = 0; iii < nnodes; iii++){
		g->nodes[iii]->isvisited = 0;
	}
}

void eClose(node * n){
	int nedges = n->nedges;
	edge * e;
	n->isvisited = 1;
	for(int iii = 0; iii < nedges; iii++) {
		e = n->edges[iii];
		if(e->lable == '#' && e->dest->isvisited == 0){
			printf("%s, ", e->dest->name);
			eClose(e->dest);
		}
	}
}


int main(int argc, char const *argv[])
{
	/* Take input from a file */
	FILE * input = fopen("NFA.txt", "r");
	
	/* declare the variables */
	int nstates, ntrans, iii, jjj;
	graph * NFA = createGraph();
	node * state;
	node * state2;
	edge * transition;

	/* construct the NFA from input */
	fscanf(input, "%d", &nstates);
	char buff[100];
	for (iii = 0; iii < nstates; ++iii){
		fscanf(input, "%s", buff);
		state = createNode(buff);
		addNode(NFA, state);
	}

	
	fscanf(input, "%d", &ntrans);
	char lable;
	for(iii = 0; iii < ntrans; iii++) {
		fscanf(input, "%s", buff);
		lable = buff[0];
		fscanf(input, "%s", buff);
		state = getNodeWithName(NFA, buff);
		fscanf(input, "%s", buff);
		state2 = getNodeWithName(NFA, buff);
		if(state && state2){
			addEdge(lable, state, state2);
		}
		else {
			printf("error: wrong transition state [ in transition: %d]\n", iii+1);
			return 0;
		}
	}

	printGraph(NFA);

	/* print eClosure of all states */
	printf("epsilon closure the states are: \n");
	nstates = NFA->nnodes;
	for(iii = 0; iii < nstates; iii++){
		printf("%s: {", NFA->nodes[iii]->name);
		clearVisits(NFA);
		eClose(NFA->nodes[iii]);
		printf("\b\b}\n");
	}
	return 0;
}