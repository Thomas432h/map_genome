# map_genome
Implémentation en C++ d'un programme de mapping de séquences génomiques pour aligner les reads sur un génome de référence, gérant les variations et les erreurs de séquençage. Le projet inclut des outils de manipulation de fichiers FASTA/FASTQ et une optimisation des structures de données pour l'indexation des k-mers.


Toolkit de Mapping Génomique

À propos

Ce dépôt contient les outils développés dans le cadre du cours de "Développement opérationnel avancé" du Master Bioinformatique à l'Université de Montpellier pour l'année universitaire 2023/2024. 

Ce projet a été guidé avec l'objectif de mapper des séquences génomiques courtes, issues de Nouvelles Générations de Séquenceurs (NGS), sur un génome de référence.

Objectif du projet

Développer une stratégie efficace pour le mapping de "reads" génomiques sur un génome de référence, en prenant en compte les erreurs de séquençage et les variations biologiques. 

L'approche adoptée se base sur l'utilisation des k-mers pour identifier les positions exactes des séquences dans le génome de référence et diagnostiquer les variations biologiques ou les erreurs de séquençage.

Installation

Pour utiliser ce toolkit, suivez les étapes suivantes :

Cloner le dépôt :

bash

git clone https://github.com/Thomas432h/map_genome.git

Se déplacer dans le répertoire du projet :

bash


cd mapping

Compiler le projet via le Makefile fourni :

css

make all

Utilisation

Lancez le programme principal après compilation :

bash

./main

Le programme coordonnera l'utilisation de tous les outils pour traiter les fichiers génomiques fournis.

Description des fichiers

main.cpp: Exécutable principal du programme.

FastqReader.cpp, SequenceReader.cpp: Classes pour la lecture des fichiers FASTQ et FASTA.

Sequence.cpp: Représente une séquence génomique et les opérations relatives.

SequenceMapper.cpp: Mappe les séquences aux marqueurs génétiques.

TableSuffixes.cpp: Gère les tables de suffixes pour la recherche efficace de séquences.

Makefile: Instructions de compilation pour le projet.

P1.fastq, sequence.fasta: Fichiers d'exemple d'entrée.

Contributions

Les contributions à ce projet sont bienvenues. Veuillez forker le dépôt et soumettre une pull request.
