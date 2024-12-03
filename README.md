TP Noté - Graphe d'une image contenant une forme 2D

PHAM Chien Cong - p2105148
SEOANE VAZQUEZ Pablo - p2413568

Ce TP Noté propose une bibliothèque pour manipuler des images en niveaux de gris (format PGM) et effectuer des calculs complexes tels que la transformée de distance, la projection de pixels, et l’union d’images. 
L'objectif principal est d'utiliser les concepts de graphes pour représenter les pixels d'une image et d'exploiter des algorithmes comme celui de Dijkstra pour calculer les plus courts chemins et les distances.

Les fonctionalités proposé:

1. Chargement et Sauvegarde d'Images
    - Chargement d'une image en niveaux de gris à partir d'un fichier au format PGM (ASCII).
    - Sauvegarde d'une image ou d'une forme transformée (par exemple, image de distance) dans un fichier PGM.

2. Transformée de Distance
    - Calcul de l'image de distance d'une forme : pour chaque pixel blanc, on calcule la distance au pixel noir le plus proche à l'aide de l'algorithme de Dijkstra (multi-sources).
    - Les distances tiennent compte des poids :
        Distance verticale/horizontale = 2.
        Distance diagonale = 3.

3. Union d'Images
    - Construction de l'image de distance de l'union de deux formes : pour chaque pixel, on prend la distance minimale entre les deux images.

4. Projection de Pixels
    - Projection d'un pixel blanc d'une image sur la forme noire la plus proche en suivant les prédécesseurs calculés par Dijkstra.
    - Projection d'un pixel blanc sur l'union de deux formes sans recalculer la transformée de distance.

5. Interface Utilisateur
    - Une interface interactive avec un menu permet de tester les fonctionnalités : chargement/sauvegarde, calcul d'images de distance, projections, etc.

Structure des fichiers:
1. Headers
    - include/graph.h : Gestion de l'image en tant que graphe. Chaque pixel est un nœud, et les relations de voisinage sont définies.
    - include/dijkstra.h : Algorithme de Dijkstra multi-sources pour calculer les plus courts chemins à partir de pixels noirs.
    - include/module.h : Interface utilisateur regroupant toutes les fonctionnalités principales.
    - include/image.h : Manipulation des images en niveaux de gris (chargement, sauvegarde, accès/modification des pixels).

2. Implémentations
    - src/graph.cpp : Manipulation des pixels et du graphe (accès, modification, affichage).
    - src/dijkstra.cpp : Calcul des plus courts chemins pour obtenir l'image de distance.
    - src/module.cpp : Fonctionnalités avancées comme la projection et l'union d'images.
    - src/main.cpp : Programme principal avec une interface interactive.
    - src/image.cpp : Gère les opérations de base sur les images PGM, telles que le chargement depuis un fichier, la sauvegarde, et l'affichage des pixels.


Instructions d'Utilisation:
1, Compilation : make
2, Éxecution: ./bin/project
