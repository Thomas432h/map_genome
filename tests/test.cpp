#include <gtest/gtest.h>
#include "FastaReader.h" // Assure-toi que cette classe existe et est bien implémentée

TEST(FastaReader, ReadsValidFileCorrectly) {
    FastaReader reader("valid.fasta"); // Assure-toi que ce fichier existe et est correct
    ASSERT_TRUE(reader.read());
    auto records = reader.getRecords();
    EXPECT_EQ(records.size(), 3); // Supposons que valid.fasta contient 3 séquences

    EXPECT_EQ(records[0].header, "Sequence 1");
    EXPECT_EQ(records[0].sequence, "ACTGACTGACTG");
    // Répéter pour d'autres séquences...
}

TEST(FastaReader, HandlesFormatErrors) {
    FastaReader reader("format_error.fasta"); // Fichier avec erreurs
    ASSERT_FALSE(reader.read());
}

// Ajouter d'autres tests pour différents scénarios
