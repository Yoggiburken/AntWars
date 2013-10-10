#ifndef CLICKABLE_HPP
#define CLICKABLE_HPP
class Clickable {
private:
protected: 
    bool                mouse_down;
public:
    virtual bool        isClicked() {}
};
#endif
