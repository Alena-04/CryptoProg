#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cryptopp/cryptlib.h>
#include <cryptopp/sha.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>

int main()
{
    using namespace CryptoPP;
    SHA1 hash;

    std::cout << "Name: " << hash.AlgorithmName() << std::endl;
    std::cout << "Digest size: " << hash.DigestSize() << std::endl;
    std::cout << "Block size: " << hash.BlockSize() << std::endl;

    std::string msg = "";
    std::string stroka;
    std::ifstream f("/home/stud/CryptoProg/hash/DO.txt");
    while (std::getline(f, stroka))
    {
        msg += stroka;
    }

    std::vector<byte> digest(hash.DigestSize());

    hash.Update((const byte *)msg.data(), msg.size());
    hash.Final(digest.data());

    std::cout << "Message: " << msg << std::endl;

    std::cout << "Digest: ";
    StringSource(digest.data(), digest.size(), true, new HexEncoder(new FileSink(std::cout)));
    std::cout << std::endl;
    return 0;
}
