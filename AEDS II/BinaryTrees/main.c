
*
     Função para calcular a altura de uma árvore binária
*/
int altura(NoArv *raiz){
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(raiz->esquerda);
        int dir = altura(raiz->direita);
        if(esq > dir)
            return esq + 1;
        else
            return dir + 1;
    }
}