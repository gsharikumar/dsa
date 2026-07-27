//{ Driver Code Starts
// Initial Template for C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 100005

struct ListNode {
    int data;
    struct ListNode *next;
};

struct graph {
    struct ListNode *head[N];
};

struct edges {
    int src, dest;
};

void show_graph(struct graph *g, int n, int m) {
    for (int i = 0; i < n; i++) {
        struct ListNode *graph_ptr = g->head[i];
        if (graph_ptr != NULL) {
            printf("%d-->", i);
        }
        while (graph_ptr != NULL) {
            printf("%d ", graph_ptr->data);
            graph_ptr = graph_ptr->next;
        }
        printf("\n");
    }
}

struct graph *create_graph(struct edges arr_edges[], int n, int m) {
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));

    for (int i = 0; i < n; i++) {
        g->head[i] = NULL;
    }

    for (int i = m - 1; i >= 0; i--) {
        int u = arr_edges[i].src, v = arr_edges[i].dest;

        // edge from u->v
        struct ListNode *newNode =
            (struct ListNode *)malloc(sizeof(struct ListNode));

        newNode->data = v;
        newNode->next = g->head[u];
        g->head[u] = newNode;
    }

    return g;
}


// } Driver Code Ends
// User function Template for C

bool isCycleDFSRecur(struct graph *g,int v,bool *visited,bool *returnStack){
    bool bRet=false;
    visited[v]=true;
    struct ListNode* ptr=g->head[v];
    returnStack[v]=true;
    for(;ptr!=NULL;ptr=ptr->next){
        if(visited[ptr->data]==false){
            bRet|=isCycleDFSRecur(g,ptr->data,visited,returnStack);
        }else if(returnStack[ptr->data]==true){
            return true;
        }
    }
    returnStack[v]=false;
    return bRet;
}

bool isCycle(struct graph *g, int n, int m) {
    // your code here
    bool bRet=false;
    bool visited[n];
    bool returnStack[n];
    memset(visited,0,sizeof(visited));
    memset(returnStack,0,sizeof(returnStack));
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            bRet|=isCycleDFSRecur(g,i,visited,returnStack);
        }
    }
    return bRet;
}

//{ Driver Code Starts.

int main() {
    int t = 1;

    while (t--) {
        int queries;
        scanf("%d", &queries);
        while (queries--) {
            int n, m;
            scanf("%d %d", &n, &m);
            struct edges arr_edges[m];
            for (int i = 0; i < m; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                arr_edges[i].src = u;
                arr_edges[i].dest = v;
            }

            struct graph *g = create_graph(arr_edges, n, m);

            bool ans = isCycle(g, n, m);
            if (ans) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        }
    }
    return 0;
}
// } Driver Code Ends