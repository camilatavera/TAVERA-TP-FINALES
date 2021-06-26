/*
 * LinkedList.c
 *
 *  Created on: Jun 23, 2021
 *      Author: caami
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


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
    this=(LinkedList*)malloc(sizeof(LinkedList));

    if(this!=NULL){
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
int ll_len(LinkedList* this) //es el getter del campo size del linkedlist.
{	int returnAux = -1;
	if(this!=NULL){
		returnAux=this->size;
	}
    return returnAux;
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
	Node* pNode=NULL;
	if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this)){

		//inicializo
		pNode=this->pFirstNode;

		for(int i=0; i<nodeIndex; i++){
			pNode=pNode->pNextNode;
		}
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
	Node* pNode=NULL;
		if(this!=NULL && nodeIndex>=0 && nodeIndex<ll_len(this)){

			//inicializo
			pNode=this->pFirstNode;

			for(int i=0; i<nodeIndex; i++){
				pNode=pNode->pNextNode;
			}
		}
	    return pNode;
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

	int ret=-1;
		Node* pNewNodo=NULL;
		Node* nodoAnterior;


		if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this) ){

			pNewNodo=(Node*)malloc(sizeof(Node));

			if(pNewNodo!=NULL){

				pNewNodo->pElement=pElement;

				if(nodeIndex==0){
					pNewNodo->pNextNode=this->pFirstNode;
					this->pFirstNode=pNewNodo;
					ret=0;
				}
				else{
					/*
					getNode(this, nodeIndex-1)->pNextNode=pNewNodo;
					pNewNodo->pNextNode=getNode(this, nodeIndex);
					*/
					nodoAnterior=getNode(this, nodeIndex-1);
					if(nodoAnterior!=NULL){
						pNewNodo->pNextNode=nodoAnterior->pNextNode;
						nodoAnterior->pNextNode=pNewNodo;
						ret=0;
					}
				}
				if(ret==0){
					this->size++;
				}
			}
			}

			return ret;

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
	int ret=-1;
	Node* pNewNodo=NULL;
	Node* nodoAnterior;


	if(this!=NULL && nodeIndex>=0 && nodeIndex<=ll_len(this) ){

		pNewNodo=(Node*)malloc(sizeof(Node));

		if(pNewNodo!=NULL){

			pNewNodo->pElement=pElement;

			if(nodeIndex==0){
				pNewNodo->pNextNode=this->pFirstNode;
				this->pFirstNode=pNewNodo;
				ret=0;
			}
			else{
				/*
				getNode(this, nodeIndex-1)->pNextNode=pNewNodo;
				pNewNodo->pNextNode=getNode(this, nodeIndex);
				*/
				nodoAnterior=getNode(this, nodeIndex-1);
				if(nodoAnterior!=NULL){
					pNewNodo->pNextNode=nodoAnterior->pNextNode;
					nodoAnterior->pNextNode=pNewNodo;
					ret=0;
				}
			}
			if(ret==0){
				this->size++;

			}
		}
		}

		return ret;

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
   int ret=-1;
   if(this!=NULL){
	   ret=addNode(this, ll_len(this), pElement);
   }
   return ret;

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
	Node *nodo=NULL;
	void* pRet=NULL;
	if(this!=NULL && index>=0 && index<ll_len(this)){
	    nodo=getNode(this, index);
	    if(nodo!=NULL){
	    	pRet=nodo->pElement;
	    }
	}
	    return pRet;
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
	int ret=-1;
	Node* node;

    if(this!=NULL  &&  index>=0 && index<ll_len(this)){

    	node=getNode(this, index);
    	if(node!=NULL){
    		node->pElement=pElement;
    	}
    	ret=0;
    }
    return ret;
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
    int ret=-1;
    Node* nodo;
    Node* nodoAnterior;


    if(this!=NULL && index>=0 && index<ll_len(this)){

    	nodo=getNode(this, index);
    	if(index==0 && nodo!=NULL){
    		this->pFirstNode=nodo->pNextNode;
    		ret=0;
    	}
    	else{
    		nodoAnterior=getNode(this, index-1);
    		if(nodo!=NULL && nodoAnterior!=NULL){
				nodoAnterior->pNextNode=nodo->pNextNode;
				ret=0;
    		}
    	}
    	if(ret==0){
    		free(nodo);
    		nodo=NULL;
			this->size--;
    	}

    }
    return ret;
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
	int i;
	int ret=-1;
	if(this!=NULL){
		ret=0;
		for(i=0; i<ll_len(this); i++){

			if(ll_remove(this, i)!=0){
				ret=-1;
				break;
			}
		}
	}
	return ret;
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
    int ret=-1;
    if(this!=NULL && ll_clear(this)==0){
    	if(ll_clear(this)==0){
    		free(this);
    		this=NULL;
    		ret=0;
    	}
    }
    return ret;
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
    int ret=-1;
    if(this!=NULL){
    	for(int i=0; i<ll_len(this); i++){
    		if(ll_get(this, i)==pElement){
    			ret=i;
    			break;
    		}
    	}
    }
    return ret;
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
    int ret=-1;
    if(this!=NULL){
    	ret=0;
    	if(ll_len(this)==0){
    		ret=1;
    	}
    }
    return ret;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente

    A diferencia de ll set que pisa el elemento del index, este crea un nodo nuevo e inserta el elemento ahi .
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
	int ret=-1;
	if(this!=NULL && index>=0 && index<=ll_len(this)){
		if(!addNode(this, index, pElement)){
			ret=0;
		}
	}
	return ret;
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
    Node* nodo;
    void* ret=NULL;
    if(this!=NULL && index>=0 && index<ll_len(this)){
    	nodo=getNode(this, index);
    	if(nodo!=NULL){
    		ret=nodo->pElement;
    		ll_remove(this, index);
    	}
    }
    return ret;
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
{
	int ret=-1;
	if(this!=NULL){
		ret=0;
		if(ll_indexOf(this, pElement)!=-1){
			ret=1;
		}
	}
	return ret;
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
    int ret=-1;
    void* pElement;
    if(this!=NULL && this2!=NULL){
    	ret=1;

    	for(int i=0; i<ll_len(this2); i++){
    		pElement=ll_get(this2, i);
    		if(ll_contains(this, pElement)==0){
    			ret=0;
    			break;
    		}
    	}
    }
    return ret;
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
    //void* pElement=NULL;
    if(this!=NULL && from>=0 && to>from && to<=ll_len(this)){

    	cloneArray=ll_newLinkedList();
    	if(cloneArray!=NULL){

			for(int i=from; i<to; i++){
				//pElement=ll_get(this, i);
				if(ll_add(cloneArray, ll_get(this, i))!=0){
					ll_deleteLinkedList(cloneArray);
					break;
				}
			}
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
	LinkedList* cloneArray=NULL;
	if(this!=NULL){
		cloneArray=ll_subList(this, 0, ll_len(this));
	}
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
    int ret=-1;
    void* auxA=NULL;
    void* auxB=NULL;

    if(this!=NULL && pFunc!=NULL && (order==1 || order==0)){

    	ret=0;

    	for(int i=0; i<ll_len(this)-1; i++){
    		for(int j=i+1; j<ll_len(this); j++){

    			auxA=ll_get(this, i);
    			auxB=ll_get(this, j);
    			if((pFunc(auxA, auxB)>0 && order) || ((pFunc(auxA, auxB))<0 && order==0)){
    				ll_set(this, j, auxA);
    				ll_set(this, i, auxB);
    			}
    		}
    	}
    }
    return ret;
}

LinkedList* ll_map(LinkedList* this, void (*pFunc)(void* element)){

	void* pAux=NULL;
	if(this!=NULL && pFunc!=NULL){

		for(int i=0; i<ll_len(this); i++){
			pAux=ll_get(this, i);
			pFunc(pAux);
			pAux=NULL;
		}
	}
	return this;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void* pElement)){

	LinkedList* llFiltrada=NULL;
	void* auxElement=NULL;

	if(this!=NULL && pFunc!=NULL){
		llFiltrada=ll_newLinkedList();
		if(llFiltrada!=NULL){

			for(int i=0; i<ll_len(this); i++){

				auxElement=ll_get(this, i);

				if(auxElement!=NULL && ll_indexOf(llFiltrada, auxElement)==-1 && pFunc(auxElement)==0){
					ll_add(llFiltrada, auxElement);
				}
			}
		}
	}
	return llFiltrada;
}

int ll_count(LinkedList* this, int(*pFunc)(void* pElement)){

	int ret=-1;
	void* auxElement;
	int retFunc;

	if(this!=NULL && pFunc!=NULL){
		ret=0;

		for(int i=0; i<ll_len(this); i++){
			auxElement=ll_get(this, i);
			if(auxElement!=NULL){
				retFunc=pFunc(auxElement);
				ret=ret+retFunc;
			}
		}
	}
	return ret;
}
