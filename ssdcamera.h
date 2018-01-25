#ifndef SSDCAMERA_H
#define SSDCAMERA_H

#include <string>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>

#include <QDebug>

#include "osutils.h"
#include "cameramodel.h"
#include "constants.h"
#include "lvframe.h"

#define TIMEOUT_DURATION 1000

class SSDCamera : public CameraModel
{
public:
    SSDCamera(const std::string search_dir, int frWidth = 640, int frHeight = 480, int dataHeight = 480);
    virtual ~SSDCamera();

    virtual bool start();

    std::string getFname();
    void readFile();
    virtual uint16_t *getFrame();

private:
    std::ifstream dev_p;
    std::string ifname;
    std::string data_dir;
    std::streampos bufsize;
    uint32_t framesize;
    const uint32_t headsize;
    std::vector<std::string> read_files;
    std::vector<std::string> xio_files;
    std::vector<std::array<uint16_t, 640*480> > frame_buf;
    uint16_t curIndex;
    uint16_t nFrames;
};

#endif // SSDCAMERA_H