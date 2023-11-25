#ifndef BYTE_MANAGER_H
#define BYTE_MANAGER_H

#include <Constants.h>

class ByteManager {

    private:
        int _currNumber;
        bool _isConversionValid;

        int _activatedBytes[NB_OF_BUTTONS];
        void initActivatedBytes();
        void updateConversion();

    public:
        ByteManager();

        void generateNewNumber();
        void handleByteButton(int byte, int btnLedPosition);
        bool isConversionValid();
};

#endif // BYTE_MANAGER_H