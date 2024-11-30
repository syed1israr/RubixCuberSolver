#include "PatternDatabase.h"

using namespace std;

PatternDatabase::PatternDatabase(const size_t size) : db(size, 0xFF), size(size), numItems(0) {
}
PatternDatabase::PatternDatabase(const size_t size, uint8_t init_val) :
        db(size, init_val), size(size), numItems(0) {
}
bool PatternDatabase::setNumMoves(const uint32_t ind, const uint8_t numMoves) {
        uint8_t oldMoves = this->getNumMoves(ind);

        //    New item is getting added
        if(oldMoves == 0xF){
                ++this->numItems;
        }

        if(oldMoves > numMoves){
                this->db.set(ind, numMoves);
                return true;
        }
        return false;
}

bool PatternDatabase::setNumMoves(const Generic_Rubix_Cube_Solver &cube, const uint8_t numMoves) {
        return  this->setNumMoves(this->getDatabaseIndex(cube),numMoves);
}

uint8_t PatternDatabase::getNumMoves(const uint32_t ind) const {
        return this->db.get(ind);
}
uint8_t PatternDatabase::getNumMoves(const Generic_Rubix_Cube_Solver&cube) const {
        return this->getNumMoves(this->getDatabaseIndex(cube));
}
size_t PatternDatabase::getSize() const {
        return this->size;
}
size_t PatternDatabase::getNumItems() const {
        return this->numItems;
}

bool PatternDatabase::isFull() const {
        return this->numItems == this->size;
}
void PatternDatabase::toFile(const string &filePath) const {
        ofstream writer(filePath, ios::out | ios::binary | ios::trunc);

        if(!writer.is_open())
                throw std::runtime_error("Failed to open the file to write");

        writer.write(
                reinterpret_cast<const char*>(this->db.data()),
                this->db.storageSize()
                );

        writer.close();

}

bool PatternDatabase::fromFile(const string &filePath) {
        std::cout << "Attempting to load file: " << filePath << std::endl;

        ifstream reader(filePath, ios::binary | ios::ate);
        if (!reader.is_open()) {
                std::cerr << "Error: Failed to open the file!" << std::endl;
                return false;
        }

        size_t fileSize = reader.tellg();
        std::cout << "File size: " << fileSize << std::endl;
        std::cout << "Expected size: " << this->db.storageSize() << std::endl;

        if (fileSize != this->db.storageSize()) {
                reader.close();
                throw std::runtime_error("Database Corrupt! Failed to open Reader: " + filePath);
        }

        reader.seekg(0, ios::beg);
        reader.read(reinterpret_cast<char*>(this->db.data()), this->db.storageSize());
        reader.close();

        this->numItems = this->size;
        return true;
}

vector<uint8_t> PatternDatabase::inflate() const {
        vector<uint8_t> inflated;
        this->db.inflate(inflated);
        return inflated;
}


void PatternDatabase::reset() {
        if(this->numItems != 0){
                this->db.reset(0xFF);
                this->numItems = 0;
        }
}



