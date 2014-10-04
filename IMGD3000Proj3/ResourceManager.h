#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::ifstream;

#include "Manager.h"
#include "Sprite.h"

#define DF_MAX_SPRITES 10000

#define DF_FRAMES_TOKEN "frames"
#define DF_HEIGHT_TOKEN "height"
#define DF_WIDTH_TOKEN "width"
#define DF_COLOR_TOKEN "color"
#define DF_END_FRAME_TOKEN "end"
#define DF_END_SPRITE_TOKEN "eof"

using std::string;

class ResourceManager : public Manager {
  private:
    ResourceManager();
    ResourceManager(ResourceManager const&);
    void operator=(ResourceManager const&);
    Sprite *p_sprite[DF_MAX_SPRITES];
    int sprite_count;
    void discardCR(string &str);

  public:
    static ResourceManager &getInstance();
    int startUp();
    void shutDown();
    int loadSprite(string filename, string label);
    int unloadSprite(string label);
    Sprite *getSprite(string label) const;
    int readLineInt(ifstream *p_file, int *p_line_number, const char *tag);
    string readLineStr(ifstream *p_file, int *p_line_number, const char *tag);
    Frame readFrame(ifstream *p_file, int *p_line_number, int width, int height);

};
