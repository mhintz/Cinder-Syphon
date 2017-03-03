#pragma once 

#include "cinder/gl/gl.h"

namespace ciSyphon {
    
typedef std::shared_ptr<class Server> ServerRef;
class Server
{
public:
    static ServerRef create()
    {
        return ServerRef( new Server() );
    }
    Server();
    ~Server();
    
	void setName( const std::string& name );
	std::string getName();

    void publishScreen();
    void publishTexture(ci::gl::TextureRef texture, bool flipped=false);
    
    bool bind(glm::vec2 size);
    void unbind();
    
protected:
    bool mBinded = false;
	void *mServer;
};

} // namespace ciSyphon