#ifndef SEQUENCEREADER_H
#define SEQUENCEREADER_H

#include <vector>
#include <string>  // Assurez-vous d'inclure pour std::string
#include "Sequence.h"  // Inclure le chemin correct si nécessaire

class SequenceReader {
public:
    // Déclaration de la méthode pour lire les séquences
    // Cette méthode retourne un vecteur de Sequence, où chaque Sequence inclut le nom du fichier source.
    std::vector<Sequence> readSequences(const std::string& filename);
};

#endif // SEQUENCEREADER_H
