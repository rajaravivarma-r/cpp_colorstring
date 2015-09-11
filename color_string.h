#include <string>
#include <cstring>
#include <memory>

class color_string : public std::string
{
    enum ColorCode {
        Black = 30,
        Red,
        Green,
        Yellow,
        Blue,
        Purple,
        Cyan,
        White
    };

public:
    // Delegating the construction to the base class
    using std::string::string;

    // Methods
    //

    color_string& red()
    {
        insertInBegining(ColorCode::Red);
        endColor();
        return *this;
    }

    color_string& green()
    {
        insertInBegining(ColorCode::Green);
        endColor();
        return *this;
    }
    color_string& yellow()
    {
        insertInBegining(ColorCode::Yellow);
        endColor();
        return *this;
    }
    color_string& blue()
    {
        insertInBegining(ColorCode::Blue);
        endColor();
        return *this;
    }
    color_string& purple()
    {
        insertInBegining(ColorCode::Purple);
        endColor();
        return *this;
    }
    color_string& cyan()
    {
        insertInBegining(ColorCode::Cyan);
        endColor();
        return *this;
    }
    color_string& white()
    {
        insertInBegining(ColorCode::White);
        endColor();
        return *this;
    }
    color_string& black()
    {
        insertInBegining(ColorCode::Black);
        endColor();
        return *this;
    }

    color_string& reset()
    {
        this->assign(backup);
        return *this;
    }

    ~color_string()
    {
        delete backup;
    }

private:

    void insertInBegining(ColorCode colorCode)
    {
        takeBackup();
        this->reset().insert(0, std::string("\033[1;") + std::to_string(colorCode) + std::string("m"));
    }

    // End color code or the terminal will continue to print
    // everything in color until it encounters this 'reset'
    // color code.
    void endColor()
    {
        this->append("\033[0m");
    }

    // Take a backup of the original string to the 'backup' variable
    //
    inline void takeBackup()
    {
        if(backup == nullptr) {
            this->backup = new char[this->length() + 1];
            std::strcpy(backup, this->c_str());
        }
    }

    // This variable used to store the string in a fresh state
    // So when applying another color code, this string can be
    // used.
    char *backup = nullptr;
};

