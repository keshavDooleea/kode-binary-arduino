#ifndef BYTE_MANAGER_H
#define BYTE_MANAGER_H

#include <Constants.h>

class ByteManager {

    private:
        int _generatedNumber;
        int _currentTotal;

    public:
        ByteManager();

        void generateNewNumber();
        void handleByteButton(int byte, bool isPressed);
        bool isConversionValid();
};

#endif // BYTE_MANAGER_H