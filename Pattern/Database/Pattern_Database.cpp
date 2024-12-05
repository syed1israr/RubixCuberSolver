//
// Created by Asus on 05-12-2024.
//

#include "Pattern_Database.h"


Pattern_Database::Pattern_Database(const size_t size) :
        database(size, 0xFF), size(size), numItems(0) {
}

Pattern_Database::Pattern_Database(const size_t size, uint8_t init_val) :
        database(size, init_val), size(size), numItems(0) {
}

bool Pattern_Database::setNumMoves(const uint32_t ind, const uint8_t numMoves) {
        uint8_t oldMoves = this->getNumMoves(ind);

        //    New item is getting added
        if(oldMoves == 0xF){
                ++this->numItems;
        }

        if(oldMoves > numMoves){
                this->database.set(ind, numMoves);
                return true;
        }
        return false;

}


bool Pattern_Database::setNumMoves(const Generic_Rubix_Cube_Solver &cube, const uint8_t numMoves) {
        return this->setNumMoves(this->getDatabaseIndex(cube), numMoves);
}

uint8_t Pattern_Database::getNumMoves(const uint32_t ind) const {
        return this->database.get(ind);
}

uint8_t Pattern_Database::getNumMoves(const Generic_Rubix_Cube_Solver &cube) const {
        return this->getNumMoves(this->getDatabaseIndex(cube));
}

size_t Pattern_Database::getSize() const {
        return this->size;
}

size_t Pattern_Database::getNumItems() const {
        return this->numItems;
}

bool Pattern_Database::isFull() const {
        return this->numItems == this->size;
}


void Pattern_Database::toFile(const string &filePath) const {

        ofstream writer(filePath, ios::out | ios::binary | ios::trunc);

        if(!writer.is_open())
                throw "Failed to open the file to write";

        writer.write(
                reinterpret_cast<const char*>(this->database.data()),
                this->database.storageSize()
                );

        writer.close();
}

bool Pattern_Database::fromFile(const string &filePath) {
        ifstream reader(filePath, ios::in | ios::ate);

        if(!reader.is_open())
                return false;

        size_t fileSize = reader.tellg();

        if(fileSize != this->database.storageSize()){
                reader.close();
                throw "Database corrupt! Failed to open Reader";
        }

        reader.seekg(0, ios::beg);
        reader.read(
                reinterpret_cast<char*> (this->database.data()),
                this->database.storageSize()
                );
        reader.close();
        this->numItems = this->size;
        return true;
}

vector<uint8_t> Pattern_Database::inflate() const {
        vector<uint8_t> inflated;
        this->database.inflate(inflated);
        return inflated;
}

void Pattern_Database::reset() {
        if(this->numItems != 0){
                this->database.reset(0xFF);
                this->numItems = 0;
        }
}