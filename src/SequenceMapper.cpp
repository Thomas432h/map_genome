#include "SequenceMapper.h" // Inclusion du fichier d'en-tête de la classe SequenceMapper

SequenceMapper::SequenceMapper(FastqReader& reader, TableSuffixes& table, const std::string& sequenceId)
    : fastqReader(reader), suffixTable(table), sequenceId(sequenceId) {} // Définition du constructeur de SequenceMapper

void SequenceMapper::mapReads() { // Définition de la méthode mapReads de la classe SequenceMapper
    auto kmers = fastqReader.getKmers(); // Obtention des k-mers à partir du lecteur FASTQ
    for (const auto& kmerEntry : kmers) { // Parcours de chaque entrée de k-mer
        std::string kmer = kmerEntry.first; // Extraction du k-mer
        auto positionsInReads = kmerEntry.second; // Récupération des positions dans les lectures
        auto positionsInReference = suffixTable.getSuffixPositions(kmer, sequenceId); // Récupération des positions dans la référence

        for (int readPos : positionsInReads) { // Parcours des positions dans les lectures
            for (int refPos : positionsInReference) { // Parcours des positions dans la référence
                mappings[kmer].push_back({readPos, refPos}); // Stockage des positions dans la structure de données de mappings
            }
        }
    }
}

void SequenceMapper::displayMapping() { // Définition de la méthode displayMapping de la classe SequenceMapper
    for (const auto& mapEntry : mappings) { // Parcours de chaque entrée dans les mappings
        std::cout << "K-mer: " << mapEntry.first << std::endl; // Affichage du k-mer
        for (const auto& posPair : mapEntry.second) { // Parcours des paires de positions
            std::cout << "  Read position: " << posPair.first << ", Reference position: " << posPair.second << std::endl; // Affichage des positions
        }
    }
}

void SequenceMapper::performAlignment() { // Définition de la méthode performAlignment de la classe SequenceMapper
    // Implémentation à venir
    std::cout << "Alignment not implemented yet." << std::endl; // Message indiquant que l'alignement n'est pas encore implémenté
}

void SequenceMapper::alignRead(const std::string& kmer, int readPosition, int referencePosition) { // Définition de la méthode alignRead de la classe SequenceMapper
    // Détails de l'alignement ici (non implémenté dans cette version)
}
