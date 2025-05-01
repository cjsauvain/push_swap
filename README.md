# push_swap

> Projet réalisé dans le cadre du cursus de l’école 42.  

## 📌 Objectif

> Implémenter un programme capable de trier une pile d’entiers à l’aide de deux piles (`a` et `b`) et d’un ensemble restreint d’opérations (swap, push, rotate, reverse rotate).  
> L’enjeu est de minimiser le nombre d’instructions produites, tout en respectant les règles imposées.

## ✅ Prérequis

- Compilateur C

## 🧪 Compilation

```bash
make
./push_swap <liste d'entiers>
```

## ⚙️ Fonctionnalités prises en charge

- Tri de listes d'entiers en utilisant uniquement :
  - `sa`, `sb`, `ss` : swap
  - `pa`, `pb` : push
  - `ra`, `rb`, `rr` : rotate
  - `rra`, `rrb`, `rrr` : reverse rotate
- Algorithmes adaptés à la taille des listes :
  - tri simple pour 2 à 5 éléments
  - tri radix ou optimisé pour listes plus longues
    
## 🧠 Concepts abordés

- Algorithme de tri Radix adapté aux contraintes du projet
