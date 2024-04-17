#include "TableSuffixes.h" // Inclusion du fichier d'en-tête de la classe TableSuffixes
#include <iostream> // Inclusion de la bibliothèque pour l'affichage

// Constructeur pour plusieurs séquences
TableSuffixes::TableSuffixes(const std::vector<Sequence>& sequences) {
    for (const auto& seq : sequences) { // Parcours de chaque séquence dans le vecteur
        std::string sequenceId = seq.getId(); // Récupération de l'identifiant de la séquence
        std::unordered_map<std::string, int> suffixTable; // Création d'une table de suffixes pour la séquence

        for (size_t i = 0; i < seq.getSequence().length(); ++i) { // Parcours de la séquence
            std::string suffix = seq.getSequence().substr(i); // Extraction du suffixe
            suffixTable[suffix] = i; // Stockage du suffixe et de son indice de début dans la table
        }

        suffixTables[sequenceId] = suffixTable; // Ajout de la table de suffixes à la map
    }
}

// Constructeur pour une seule séquence
TableSuffixes::TableSuffixes(const Sequence& sequence) {
    std::string sequenceId = sequence.getId(); // Récupération de l'identifiant de la séquence
    std::unordered_map<std::string, int> suffixTable; // Création d'une table de suffixes pour la séquence

    for (size_t i = 0; i < sequence.getSequence().length(); ++i) { // Parcours de la séquence
        std::string suffix = sequence.getSequence().substr(i); // Extraction du suffixe
        suffixTable[suffix] = i; // Stockage du suffixe et de son indice de début dans la table
    }

    suffixTables[sequenceId] = suffixTable; // Ajout de la table de suffixes à la map
}

// Méthode pour obtenir les positions des suffixes correspondant à un k-mer dans une séquence
std::vector<int> TableSuffixes::getSuffixPositions(const std::string& kmer, const std::string& sequenceId) const {
    std::vector<int> positions; // Initialisation du vecteur pour stocker les positions des suffixes correspondants
    auto it = suffixTables.find(sequenceId); // Recherche de la séquence dans la map des tables de suffixes
    if (it != suffixTables.end()) { // Vérification si la séquence est trouvée
        const auto& table = it->second; // Récupération de la table de suffixes de la séquence
        for (const auto& pair : table) { // Parcours de chaque paire (suffixe, indice) dans la table
            if (pair.first.substr(0, kmer.length()) == kmer) { // Vérification si le suffixe correspond au k-mer
                positions.push_back(pair.second); // Stockage de l'indice de début du suffixe dans le vecteur de positions
            }
        }
    }
    return positions; // Retour des positions des suffixes correspondants
}

// Méthode pour imprimer toutes les tables de suffixes
void TableSuffixes::printAllSuffixTables() const {
    std::cout << "Tables des suffixes :" << std::endl; // Affichage du titre
    for (const auto& pair : suffixTables) { // Parcours de chaque paire (identifiant de séquence, table de suffixes) dans la map
        std::cout << "Séquence ID : " << pair.first << std::endl; // Affichage de l'identifiant de la séquence
        std::cout << "Suffixes :" << std::endl; // Affichage de l'en-tête pour les suffixes de la séquence
        for (const auto& suffixPair : pair.second) { // Parcours de chaque paire (suffixe, indice) dans la table de suffixes
            std::cout << "Suffixe : " << suffixPair.first << ", Indice de début : " << suffixPair.second << std::endl; // Affichage du suffixe et de son indice de début
        }
        std::cout << "--------------------------" << std::endl; // Affichage d'une ligne de séparation entre les tables de suffixes
    }
}
