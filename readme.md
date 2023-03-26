## A faire avant rendu:

METTRE MA LIBFT :D

## Steps

1.	Pre-Sort
	- Trouver des medianes
	- Virer les elements dans b jusqu'avoir 3 elements
2.	Calcul de coups
	- Ecrire une fonction qui prend un element dans b et qui trouve le parent dans a
	- Faire une fonction qui donne une liste d'index de prix [0, 1, 2, 3, -2, -1]
	- Une boucle qui trouve l'element le moins cher a rotate
	- Une fonction qui fait les movements (rotation) de l'element donne

## Pensees du soir bonsoir
En gros I think I remember
Le but c'est de tout foutre dans b (sauf trois element maybe)
Apres, on calcule la fct de coups (donc en gros un array qui donne a chaque valeur dans b un numero selon ce qui est - cher) aka -> rb est - cher, le coups est positif selon combien de coups il faut faire
-> rrb est moins cher, le coups est negatif selon combien de coups il faut faire
-> coups montre juste cmb de coups il faut pour remonter au sommet
-> on fait ensuite la meme chose pour a -> combien chaque coups doit etre rotate.
-> on calcule ensuite (grace aux indices que l'on a trouve en faisant le sort) le meilleur endroit pour chaque element de b, si on a 
1[0] 5[2]
4[1] 6[3]
7[4] 8[5]
a 	 b
1 4 5 6 7 8
-> On prend un indice dans b (2 par exemple)
-> 5[2] est entre 0 et 1
-> le coups de deplacer 5 est de 0, le coups de deplacer 4[1] au sommet de la pile est de 1 -> 1 au total (ra)
-> pour 3, le coups de deplacer 6[3] au sommet de la pile est de 1 et le coups de deplacer 4 au sommet de la pile est de -1 -> soit 2 au total (rb et rra)
-> le coups de deplacer 8[5] au sommet de la pile est de -1 et pas besoin de deplacer 1[0] -> -1 au total (rrb)

Si on avait -1 et -1 on pourrait ainsi faire rrr
-> 1 et 1 -> rr
-> on trie ainsi la liste

