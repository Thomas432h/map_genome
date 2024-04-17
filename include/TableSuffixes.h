#ifndef TABLE_SUFFIXES_H
#define TABLE_SUFFIXES_H

#include <vector> // Inclusion de la bibliothèque pour les vecteurs
#include <string> // Inclusion de la bibliothèque pour les chaînes de caractères
#include <unordered_map> // Inclusion de la bibliothèque pour les tables de hachage
#include "Sequence.h" // Inclusion du fichier d'en-tête pour la classe Sequence

class TableSuffixes {
private:
    std::unordered_map<std::string, std::unordered_map<std::string, int>> suffixTables; // Table de hachage pour stocker les tables de suffixes

public:
    explicit TableSuffixes(const std::vector<Sequence>& sequences); // Déclaration du constructeur pour plusieurs séquences
    explicit TableSuffixes(const Sequence& sequence); // Déclaration du constructeur pour une seule séquence

    std::unordered_map<std::string, int> getSuffixTable(const std::string& sequenceId) const; // Déclaration de la méthode pour obtenir la table de suffixes
    std::vector<int> getSuffixPositions(const std::string& kmer, const std::string& sequenceId) const; // Déclaration de la méthode pour obtenir les positions des suffixes

    void printAllSuffixTables() const; // Déclaration de la méthode pour imprimer toutes les tables de suffixes
};

#endif // TABLE_SUFFIXES_H
