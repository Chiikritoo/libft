# libft
**Ta propre bibliothèque rien que pour toi.**

## Résumé

Ce projet a pour objectif de vous faire coder en C une bibliothèque de fonctions usuelles que vous pourrez utiliser pour vos prochains projets.

## Introduction

La programmation en C est une activité très laborieuse dès lors que l’on n’a pas accès à toutes ces petites fonctions usuelles très pratiques. C’est pourquoi nous vous proposons à travers ce projet de prendre le temps de récrire ces fonctions, de les comprendre et de vous les approprier. Vous pourrez alors réutiliser votre bibliothèque pour travailler efficacement sur vos projets suivants en C. Prenez le temps d’enrichir votre libft tout au long de l’année. Cependant, pour chacun de vos projets futurs, veillez toujours à vérifier quelles sont les fonctions autorisées !

| Nom du programme | libft.a |
| --- | --- |
| Fichiers de rendu | Makefile, libft.h, ft_*.c |
| Makefile | NAME, all, clean, fclean, re |
| Fonctions externes autorisées | Détails ci-dessous |
| Libft autorisée | n/a |
| Description | Créez votre propre bibliothèque contenant des fonctions utiles pour la suite de votre cursus. |

---

J'espère que cela répond à vos besoins !

## Fonctions disponibles

### Manipulation de caractères

| Fonction | Prototype | Description |
| --- | --- | --- |
| ft_isalnum | int ft_isalnum(int c); | Vérifie si le caractère est alphanumérique |
| ft_isalpha | int ft_isalpha(int c); | Vérifie si le caractère est alphabétique |
| ft_isacii | int ft_isascii(int c); | Vérifie si le caractère est un caractère ASCII valide |
| ft_isdigit | int ft_isdigit(int c); | Vérifie si le caractère est un chiffre |
| ft_isprint | int ft_isprint(int c); | Vérifie si le caractère est imprimable |
| ft_toupper | int ft_toupper(int c); | Convertit le caractère en majuscule |
| ft_tolower | int ft_tolower(int c); | Convertit le caractère en minuscule |

### Manipulation de chaînes de caractères

| Fonction | Prototype | Description |
| --- | --- | --- |
| ft_strchr | char *ft_strchr(const char *s, int c); | Recherche un caractère dans une chaîne |
| ft_strdup | char *ft_strdup(const char *s); | Duplique une chaîne |
| ft_strlcat | size_t ft_strlcat(char *dst, const char *src, size_t size); | Concatène deux chaînes |
| ft_strlcpy | size_t ft_strlcpy(char *dst, const char *src, size_t size); | Copie une chaîne |
| ft_strlen | size_t ft_strlen(const char *s); | Retourne la longueur d'une chaîne |
| ft_strncmp | int ft_strncmp(const char *s1, const char *s2, size_t n); | Compare n caractères de deux chaînes |
| ft_strnstr | char *ft_strnstr(const char *big, const char *little, size_t len); | Recherche une sous-chaîne |
| ft_strrchr | char *ft_strrchr(const char *s, int c); | Recherche un caractère dans une chaîne (de la fin) |
| ft_strjoin | char *ft_strjoin(char const *s1, char const *s2); | Joint deux chaînes |
| ft_strmapi | char *ft_strmapi(char const *s, char (*f)(unsigned int, char)); | Applique une fonction à chaque caractère de la chaîne |
| ft_strtrim | char *ft_strtrim(char const *s1, char const *set); | Retire les caractères indésirables au début et à la fin |
| ft_substr | char *ft_substr(char const *s, unsigned int start, size_t len); | Retourne une sous-chaîne |
| ft_split | char **ft_split(char const *s, char c); | Sépare une chaîne en plusieurs sous-chaînes |
| ft_striteri | void ft_striteri(char *s, void (*f)(unsigned int, char*)); | Applique une fonction à chaque caractère de la chaîne |

### Conversion et mathématiques

| Fonction | Prototype | Description |
| --- | --- | --- |
| ft_atoi | int ft_atoi(const char *str); | Convertit une chaîne en entier |
| ft_itoa | char *ft_itoa(int n); | Convertit un entier en chaîne |

### Manipulation de la mémoire

| Fonction | Prototype | Description |
| --- | --- | --- |
| ft_bzero | void ft_bzero(void *s, size_t n); | Met à zéro une zone mémoire |
| ft_calloc | void *ft_calloc(size_t nmemb, size_t size); | Alloue et initialise une zone mémoire |
| ft_memchr | void *ft_memchr(const void *s, int c, size_t n); | Recherche un caractère dans une zone mémoire |
| ft_memcmp | int ft_memcmp(const void *s1, const void *s2, size_t n); | Compare deux zones mémoire |
| ft_memcpy | void *ft_memcpy(void *dest, const void *src, size_t n); | Copie une zone mémoire vers une autre |
| ft_memmove | void *ft_memmove(void *dest, const void *src, size_t n); | Déplace une zone mémoire vers une autre |
| ft_memset | void *ft_memset(void *s, int c, size_t n); | Remplit une zone mémoire avec un caractère donné |

### Entrées/Sorties

| Fonction | Prototype | Description |
| --- | --- | --- |
| ft_putchar_fd | void ft_putchar_fd(char c, int fd); | Écrit un caractère sur un descripteur de fichier |
| ft_putendl_fd | void ft_putendl_fd(char *s, int fd); | Écrit une chaîne suivie d'un retour à la ligne sur un descripteur de fichier |
| ft_putnbr_fd | void ft_putnbr_fd(int n, int fd); | Écrit un nombre sur un descripteur de fichier |
| ft_putstr_fd | void ft_putstr_fd(char *s, int fd); | Écrit une chaîne sur un descripteur de fichier |

### Manipulation de listes

| Fonction | Prototype | Description |
| --- | --- | --- |
| ft_lstadd_back | void ft_lstadd_back(t_list **lst, t_list *new); | Ajoute un élément à la fin d'une liste |
| ft_lstadd_front | void ft_lstadd_front(t_list **lst, t_list *new); | Ajoute un élément au début d'une liste |
| ft_lstclear | void ft_lstclear(t_list **lst, void (*del)(void *)); | Supprime et libère la mémoire de la liste |
| ft_lstdelone | void ft_lstdelone(t_list *lst, void (*del)(void *)); | Supprime un élément de la liste |
| ft_lstiter | void ft_lstiter(t_list *lst, void (*f)(void *)); | Applique une fonction à chaque élément de la liste |
| ft_lstlast | t_list *ft_lstlast(t_list *lst); | Retourne le dernier élément de la liste |
| ft_lstmap | t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)); | Applique une fonction à chaque élément de la liste et crée une nouvelle liste |
| ft_lstnew | t_list *ft_lstnew(void *content); | Crée un nouvel élément de liste |
| ft_lstsize | int ft_lstsize(t_list *lst); | Retourne la taille de la liste |
