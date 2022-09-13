#include <irrlicht/irrlicht.h>
#include <stdexcept>
#include <iostream>

 using namespace irr;

void DoAll(){
    throw std::runtime_error("Mi ERROR de Exepcion!!");
}

int game(){
    // start up the engine
    IrrlichtDevice *device = createDevice(video::EDT_SOFTWARE,
        core::dimension2d<u32>(640,480));

    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* scenemgr = device->getSceneManager();

    device->setWindowCaption(L"Hello World!");

    DoAll();

    // draw everything
    while(device->run() && driver)
    {
        driver->beginScene(true, true, video::SColor(255,255,255,255));
        scenemgr->drawAll();
        driver->endScene();
    }

    

    // delete device
    device->drop();
    return 0;
}
 int main()
 {
    try {
        game();
    }catch(std::exception const& e){
        std::cerr << "EXEPTION:";
        std::cerr << "   " << e.what() << "\n\n";
    }
 }