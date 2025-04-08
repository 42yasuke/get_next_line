# 📄 get_next_line

**get_next_line** est un projet qui consiste à créer une fonction permettant de lire une ligne d'un fichier à la fois. La fonction `get_next_line` doit être capable de lire un fichier ou l'entrée standard ligne par ligne, et ce, de manière efficace. Ce projet permet de comprendre la gestion des fichiers et des buffers en C.

## 🛠️ Objectif

L'objectif de ce projet est de créer une fonction qui lit une ligne d'un fichier à chaque appel. Cette fonction doit gérer les fichiers de manière optimale, sans gaspiller de mémoire ni de ressources. Tu dois implémenter cette fonction de manière indépendante, sans utiliser des fonctions de bibliothèque telles que `getline`.

---

## 🧩 Fonctionnalités Implémentées

- La fonction `get_next_line` doit lire une ligne de n'importe quel fichier ou de l'entrée standard.
- Elle doit gérer les fichiers de manière optimisée, en utilisant des tampons (buffers) pour ne pas tout lire d'un coup.
- La gestion des erreurs et de la mémoire doit être propre et efficace.

---

## 🧪 Compilation et Utilisation

### Compilation

Le projet utilise un `Makefile` pour faciliter la compilation.

```bash
make

Pour nettoyer les fichiers objets :

```bash
make clean

Pour supprimer tous les fichiers compilés (objets + exécutable) :

```bash
make fclean

Pour recompiler le projet :

```bash
make re

### Utilisation

Une fois le projet compilé, tu peux utiliser get_next_line comme suit

```c
#include "get_next_line.h"
#include <stdio.h>

int main()
{
    char *line;
    int fd = open("myfile.txt", O_RDONLY);  // Ouvrir un fichier en lecture
    while (get_next_line(fd, &line) > 0)    // Lire ligne par ligne
    {
        printf("Ligne lue : %s\n", line);
        free(line);  // Libérer la mémoire après utilisation
    }
    close(fd);  // Fermer le fichier
    return 0;

---
