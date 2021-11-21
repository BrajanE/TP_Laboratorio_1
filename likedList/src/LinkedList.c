#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;
    this=(LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int rtn = -1;
    if(this!=NULL)
    {
    	rtn = this->size;
    }
    return rtn;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	Node* pAuxNode; //igualar a null genero errores en la siguiente funcion
	int posicion=0;
	int len=ll_len(this);
	if (this!=NULL && (nodeIndex>=0 && nodeIndex<len))//no puede ir "<=len" imagino que no puede guardar el ultimo nodo NULL o algo asi, es condicion del testeo
	{
		pAuxNode=this->pFirstNode;//toma el primer nodo y arranca el bucle
		while(posicion!=nodeIndex)
		{
			pAuxNode=pAuxNode->pNextNode;
			posicion++;
		}
		pNode=pAuxNode;
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    Node* pNodeNuevo = (Node*) malloc(sizeof(Node));
    pNodeNuevo->pElement=pElement;
    pNodeNuevo->pNextNode=NULL;


    Node* pNodeAnterior;
    Node* pNodeSiguiente;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=len)
    {
    	if(nodeIndex==0)//primera posicion
    	{
    		pNodeNuevo->pNextNode=this->pFirstNode;
    		this->pFirstNode=pNodeNuevo;
    		returnAux=0;
    	}
    	else if(this->pFirstNode==NULL)//ultima posicion siempre apunta a null
    	{
    		this->pFirstNode=pNodeNuevo;
    		returnAux=0;

    	} else //posiciones intermedias
    	{
    		pNodeAnterior=getNode(this, nodeIndex-1);//toma el nodo anterior al ingresado (-1)
    		pNodeSiguiente=pNodeAnterior->pNextNode;//guarda el nodo siguiante al nodo anterior, seria al index original
    		pNodeAnterior->pNextNode=pNodeNuevo; //ahora el nodo anterior (-1) apunta al nodo que queremos agregar, el nuevo
    		pNodeNuevo->pNextNode=pNodeSiguiente; //el nuevo nodo se agrego en la posicion deseada y apunta al siguiente nodo que tiene guardado el que estaba originalmente en dicho lugar
    		returnAux=0;
    	}
    	if(returnAux==0)
    	{
    		this->size++;
    	}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	int nodeIndex=ll_len(this);
    	returnAux=addNode(this, nodeIndex, pElement);
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len=ll_len(this);
    if(this!=NULL && index>=0 && index<len)//igual que en get node
    {
    	Node* pNodeObtenido;
    	pNodeObtenido=getNode(this, index);
    	returnAux=pNodeObtenido->pElement;
    }

    return returnAux;//tiene que retornar el pElement, que esta en un nodo
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len=ll_len(this);
    Node* pNodeBuscado;
    if(this!=NULL && index>=0 && index<len)
    {
    	pNodeBuscado=getNode(this, index);
    	pNodeBuscado->pElement=pElement;
    	returnAux=0;
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len=ll_len(this);
    Node* pNodeBuscado;
    Node* pNodeAnterior;
    if(this!=NULL && index>=0 && index<len)
    {
    	if(index==0)//primera posicion
    	{
    		pNodeBuscado=this->pFirstNode;
    		this->pFirstNode=pNodeBuscado->pNextNode;
    		//se cambia las direcciones a la que apuntan,
    		free(pNodeBuscado);
    		returnAux=0;
    	} else //posiciones intermedias
    	{
    		pNodeBuscado=getNode(this, index);
    		pNodeAnterior=getNode(this, index-1);
    		pNodeAnterior->pNextNode=pNodeBuscado->pNextNode;
    		//hacemos que apunte al nodo siguiente al buscado
    		free(pNodeBuscado);
    		returnAux=0;
    	}
    	if(returnAux==0)
    	{
    		this->size--;
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len=ll_len(this);

    if(this!=NULL)
    {
    	for(int i=0;i<len;i++)
    	{
    		returnAux=ll_remove(this,i);
    		if(returnAux==-1)
    		{
    			break;
    		}
    	}
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
    	ll_clear(this); //eliminamos los nodos
    	free(this); //eliminamos la lista, la memoria reservada
    	returnAux=0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1; //tiene que retornar la posicion
    int len=ll_len(this);
    Node* pNodeBuscado;
    if(this!=NULL)
    {
    	for(int i=0;i<len;i++)
    	{
    		pNodeBuscado=getNode(this,i);
    		if(pNodeBuscado->pElement==pElement)
    		{
    			returnAux=i;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1; //por error
    int len=ll_len(this);
    if(this!=NULL) //si la lista no esta vacia
    {
    	returnAux=0;
    }
    if(len==0) //si la lista esta vacia
    {
    	returnAux=1;
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{	//tiene que tener un size++, retoirnar 0 si se agrega correctamente
	//es el mismo que ADDNODE!
    int returnAux = -1;
    int len=ll_len(this);
    if(this!=NULL && index>=0 && index<=len)
    {
    	returnAux=addNode(this, index, pElement);
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len=ll_len(this);
    Node* pNodeBuscado;
    if(this!=NULL && index>=0 && index<len)
    {
    	pNodeBuscado=getNode(this, index);
    	returnAux=pNodeBuscado->pElement;
    	ll_remove(this, index);//eliminamos el elemento de ese nodo
    }
    //retorna el elemento que tiene ese nodo
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{	//el "indexof" toma pelement y compara con alguno del array, devuelve la posicion donde esta ese pelement
    int returnAux = -1; //error
    int index; //control de indexof
    if(this!=NULL)
    {
    	index=ll_indexOf(this, pElement);
    	returnAux=0; //si no entra al if es por que no tiene elementos
    	//iba antes del if sino vuelve a cambiar el retorno a 0
    	if(index!=-1)
    	{
    		returnAux=1;//si el indice devuelve una posicion valida ==1
    	}

    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len1=ll_len(this);
    int len2=ll_len(this2);
    void* pAuxElement;

    if(this!=NULL && this2!=NULL)
    {
    	returnAux=0;
    	if(len2>0 && len1>0)
    	{
			for(int i=0;i<len2;i++)
			{
				pAuxElement=ll_get(this2, i);
				returnAux=ll_contains(this, pAuxElement);
				if(returnAux==0)
				{
					break;
				}
			}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    LinkedList* pNuevaLista=ll_newLinkedList();
    int len=ll_len(this);
    void* pNuevoElement;
    if(this!=NULL && pNuevaLista!=NULL) //&& (from>=0 && from<=len) && (to>from && to<=len))
    {	// (from<0 || from>len) || (to<=from || to>len)
    	if((from>=0 && from<=len) && (to>from && to<=len))
    	{
    	//tenemos que obtener un elemento y pegarlo en la nueva lista, de from a to
    		for(int i=from;i<to;i++)
    		{
    			pNuevoElement=ll_get(this, i);//obtenemos el lemento de la posicion
    			ll_add(pNuevaLista, pNuevoElement);//agregamos una nueva lista y elemento con su correspondiente nodo
    		}
    		cloneArray=pNuevaLista; //clonamos para que lo retorne, tal vez sea innecesario
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    return returnAux;

}

