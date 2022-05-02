#define MAPMAXSIZE 100 //��ͼ������Ϊ 100x100 

#define MAXINT 8192 //����һ���������, ��ͼ������������벻�ᳬ���� 

#define STACKSIZE 65536 //���������ڵ�Ķ�ջ��С 

#define tile_num(x,y) ((y)*map_w+(x)) //�� x,y ����ת��Ϊ��ͼ�Ͽ�ı�� 

#define tile_x(n) ((n)%map_w) //�ɿ��ŵó� x,y ���� 

#define tile_y(n) ((n)/map_w) 

// ���ṹ, �Ƚ�����, �Ǵ�Ҷ�ڵ�����ڵ㷴������ 

typedef struct node *TREE; 

struct node {

int h;

int tile;

TREE father;

};

typedef struct node2 *LINK;

struct node2 {

TREE node;

int f;

LINK next;

};

LINK queue; // ����û�д�������߷����Ľڵ� 

TREE stack[STACKSIZE]; // �����Ѿ�������Ľڵ� (��������ͷ�) 

int stacktop;

char map[][6]={{'x','x','x','x','x','x'},

               {'x','e',' ',' ',' ','x'},

               {'x','x',' ','x',' ','x'},

               {'x','x',' ',' ',' ','x'},

               {'x','x','x','x','s','x'},

               {'x','x','x','x','x','x'} };//��ͼ���� 

int dis_map[MAPMAXSIZE][MAPMAXSIZE];//��������·��ʱ,�м�Ŀ������Ž� 

int map_w,map_h;//��ͼ��͸� 

int start_x,start_y,end_x,end_y; //�ص�,�յ����� 

// ·��Ѱ�������� 

void findpath(int *path)

{

 //printf("%d,%d,%d,%d",start_x,start_y,end_x,end_y);  

TREE root;

int i,j;

stacktop=0;

for (i=0;i<map_h;i++)

for (j=0;j<map_w;j++)

dis_map[i][j]=MAXINT;

init_queue();

root=(TREE)malloc(sizeof(*root));

root->tile=tile_num(start_x,start_y);

root->h=0;

root->father=NULL;

enter_queue(root,judge(start_x,start_y));

for (;;) {

int x,y,child;

TREE p;

root=get_from_queue();

if (root==NULL) {

*path=-1;

return;

}

x=tile_x(root->tile);

y=tile_y(root->tile);

if (x==end_x && y==end_y) break;// �ﵽĿ�ĵسɹ����� 

child=trytile(x,y-1,root);//���������ƶ� 

child&=trytile(x,y+1,root);//���������ƶ� 

child&=trytile(x-1,y,root);//���������ƶ� 

child&=trytile(x+1,y,root);//���������ƶ� 

if (child!=0)

pop_stack();// ����ĸ�����������ƶ�,�ͷ�������ڵ� 

}

// ������������������·�������� path[] �� 

for (i=0;root;i++) {

path[i]=root->tile;

root=root->father;

//printf("pathis %d",path[i]);

}

path[i]=-1;

freetree();

}

// ���ۺ���,���� x,y ��Ŀ�ĵصľ���,����ֵ���뱣֤��ʵ��ֵС 

int judge(int x,int y)

{ 

int distance;

distance=abs(end_x-x)+abs(end_y-y);

return distance;

}

// ������һ���ƶ��� x,y ���з� 

int trytile(int x,int y,TREE father)

{

TREE p=father;

int h;

if (map[y][x]=='x') return 1; // ��� (x,y) �����ϰ�,ʧ�� 

while (p) {

if (x==tile_x(p->tile) && y==tile_y(p->tile)) return 1; //��� (x,y) ��������,ʧ�� 

p=p->father;

}

h=father->h+1;

if (h>=dis_map[y][x]) return 1;// ��������и��õķ����ƶ��� (x,y) ʧ�� 

dis_map[y][x]=h;// ��¼��ε� (x,y) �ľ���Ϊ��ʷ��Ѿ��� 

// ���ⲽ���������������� 

p=(TREE)malloc(sizeof(*p));

p->father=father;

p->h=father->h+1;

p->tile=tile_num(x,y);

enter_queue(p,p->h+judge(x,y));

return 0;

}
