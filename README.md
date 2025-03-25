***NOTE DE L'AUTEUR (Saphir Gobbi): Les fichiers code.c et code.h ont été modifié afin de complété l'activité.***

# Sujet de l'activité

Dans cette partie de l'activité, vous devez écrire des fonctions de manipulation de codes génétiques en utilisant la structure de données que vous souhaitez. Il n'y pas de contrainte particulière dans l'exercice et vous pouvez utiliser librement la bibliothèque standard. ( Cet exercice n'est pas un exercice de biologie et nous utiliserons une représentation et des opérations qui ne font qu'approximer ce qui se passe réellement. )

Un code génétique est une séquence de codons. Chaque codon correspond à un acide aminé parmi un ensemble de quatre possibles généralement représentés par les lettres A, C, G, et T. Un code génétique est donc une séquence dont tous les éléments sont l'une de ces quatre lettres.

## Modification a faire

Vous ne modifierez uniquement les fichiers **code.c** et **code.h**.

Vous devez écrire des fonctions qui créent de nouveaux codes génétiques pour toute opération. Tous les codes créés sont donc immuables et gardent leur valeur après une opération les utilisant comme opérande. La seule exception est la fonction ***code_ajoute***, qui modifie le code génétique passé en paramètre en lui ajoutant un codon.

### Pour tester les allocations votre code :
- ``make test_Q1`` suivis de ``./test_Q1``
- ``make test_Q2`` suivis de ``./test_Q2``
