#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 

 
 

struct arbol
{
    int num;
    struct arbol *izq;
    struct arbol *der;
 
};
 
 

void crear_arbol(struct arbol *&raiz)
{
  raiz=NULL;
 
};
 
 
void insertar_arbol(struct arbol *&raiz, int n)
{
  struct arbol *p,*ant,*nuevo;
 
     nuevo=new struct arbol;
 
     nuevo->num =n;
     nuevo->der =NULL;
     nuevo->izq =NULL;
 
     if(raiz!=NULL)
     {
       p=raiz;         
       ant=raiz;      

       while(p!=NULL)
       {
         ant=p;
          if(p->num>n)
             p=p->izq;
          else
            p=p->der;
       }
       
       if(ant->num>n)
          ant->izq=nuevo;
       else
         ant->der=nuevo;
     }
       else
         raiz=nuevo;
 }
 
bool esta_arbol(struct arbol *raiz, int n)
{
   bool res;
   struct arbol *p;
 
   p=raiz;
   res=false;
   while(p!=NULL && res==false)
   {
     if(p->num==n)
        res=true;
     else
       if(p->num>n)
         p=p->izq;
     else
        p=p->der;
 
   }
 
   return res;
 
}
 
void mostrar_arbol(struct arbol *raiz)
{
  if(raiz!=NULL) 
  {
    mostrar_arbol(raiz->izq); 
    printf("\n %d",raiz->num); 
    mostrar_arbol(raiz->der); 
  }
};
 
void borrar_dos_hijos(struct arbol *&raiz,struct arbol *p, struct arbol *ant, int n)
{
   struct arbol *dere;
   struct arbol *izqui;
   struct arbol *anterior;
 
   izqui=p->izq;
   anterior=izqui;
   dere=izqui;
 
   while(dere->der!=NULL)
   {
     anterior=dere;
     dere=dere->der;
   }
   if(izqui->der!=NULL)
   {
      anterior->der=dere->izq;
      p->num=dere->num;
      delete(dere);
   }
   else
   {
      p->izq=izqui->izq;
      p->num=izqui->num;
      delete(izqui);
   }
 
}
 
void borrar_hoja(struct arbol *&raiz,struct arbol *p,struct arbol *ant,int n)
{
  if(p==raiz)
      raiz=NULL;
  else
    if(ant->der==p)
       ant->der=NULL;
    else
      ant->izq=NULL;
 
      delete(p);
 
}
 
void borrar_un_hijo(struct arbol *&raiz,struct arbol *p,struct arbol *ant,int n)
{
   if(p==raiz)
    if(raiz->der!=NULL)
        raiz=raiz->der;
    else
       raiz=raiz->izq;
 
    else
      if(ant->der==p)
        if(p->der!=NULL)
            ant->der=p->der;
         else
            ant->der=p->izq;
            else if(p->der!=NULL)
                ant->izq=p->der;
                  else ant->izq=p->izq;
 
                  delete(p);
 
}
void borrar_de_arbol(struct arbol *&raiz,struct arbol *p,struct arbol *ant,int n)
{
   if(p->der==NULL && p->izq==NULL)
      borrar_hoja(raiz,p,ant,n);
   else
     if(p->der!=NULL && p->izq!=NULL)
         borrar_dos_hijos(raiz,p,ant,n);
      else
        borrar_un_hijo(raiz,p,ant,n);
 
};
 
void eliminar_de_arbol(struct arbol *&raiz,int n)
{
  struct arbol *p, *ant, *nuevo;
 
  p=raiz;
  ant=raiz;
 
  while(p->num!=n)
  {
    ant=p;
      if(p->num>n)
         p=p->izq;
      else
         p=p->der;
  }
  borrar_de_arbol(raiz,p,ant,n);
 
};
 
 
int mostrar_nivel(struct arbol* raiz, int numero)
{
 
    int cont;
    bool seguir=true;
 
    if(raiz!=NULL && seguir) 
    {
      mostrar_nivel(raiz->izq, numero); 
 
      if(raiz->num == numero)
      {
        seguir=false;
            return false;
      }
      else
         if(seguir)
             cont++;
 
       mostrar_nivel(raiz->der, numero);
    }
    return true;
}
 
 
int mostrar_nivel(struct arbol* raiz, int numero){
struct arbol* p;
   p = raiz;
   int cont = 0;
   while(p->der != NULL)
  {
    if(p->num == numero)
     return cont;
           p = p->der;
  }
  return -1;
}
 
 
void detecta_nivel(struct arbol *&raiz,int num )
{
    struct arbol *p;
 
    p=raiz;
    int cont =0;
 
    while(p->num!=num)
    {
      if(p->num>num)
      {
        p=p->izq;
        cont++;
 
      }
      else
      {
        p=p->der;
        cont++;
      }
    }
}
 
 
 
void leer_numero(char cade[30], int &a)
{
 
  printf("\n %s:",cade);
  scanf("%d",&a);
  fflush(stdin);
 
}
 
 
void pausar()
{
   printf("\n");
   system("pause");
 
}

 
int main()
{
 
    int i;
    struct arbol *ar; 
    int x,nro;
 
     crear_arbol(ar); 
 
    printf("\nIngrese un numero para insertar en el arbol: ");
    scanf("%d",&nro);
    fflush(stdin);
 
 
    while(nro!=0)
    {

       if(esta_arbol(ar,nro)== false)
           insertar_arbol(ar,nro); 
       else
          printf("\nEl numero esta repetido en el arbol !!! ");
 
          printf("\nIngrese un numero para insertar en el arbol: ");
          scanf("%d",&nro);
          fflush(stdin);
 
    }
    
    mostrar_arbol(ar);
    printf("\n");
 
    
 
    printf("_____________________________________________________\n");
    printf("\n ingrese un numero para eliminar del arbol: ");
    scanf("%d", &nro);
    fflush(stdin);
 
    while(nro!=0)
    {
      if(esta_arbol(ar,nro)==true)
          eliminar_de_arbol(ar,nro);
      else
         printf("\nel numero NO esta en el arbol !!! ");
 
         printf("\nIngrese un numero para eliminar del arbol: ");
         scanf("%d",&nro);
         fflush(stdin);
 
    }
    mostrar_arbol(ar);
    printf("\n");
 
    printf("\nIngresar un numero y mostrar en que nivel del arbol se encuentra: ");
    scanf("%d",&nro);
    fflush(stdin);
 
    
 
    int nivel=mostrar_nivel(ar,nro);
    printf("\n el numero esta en  el nivel %d ", nivel);
    printf("\n");
 
 
 
    pausar();
 
    return 0;
 
}
