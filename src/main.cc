#include "mead.h"
#include "mead_panel.h"
#include "mead_text.h"

int main() 
{
    Mead::Terminal& term { Mead::Terminal::GetInstance() };

    Mead::Panel root { Mead::Panel::FullScreen() };
    Mead::Panel left { Mead::XPercent(50), Mead::YPercent(100), Mead::Location::LEFT };
    Mead::Panel right { Mead::XPercent(50), Mead::YPercent(100), Mead::Location::RIGHT };

    Mead::Text left_text { "Hello, World", Mead::Location::CENTER };
    Mead::Text right_text { "Hello, World", Mead::Location::CENTER };


    left.Add(left_text);
    right.Add(right_text);
    root.Add(left);
    root.Add(right);

    while (true)
    {
        root.Display();
        if (term.GetKey() == 'q') break;
    }

    return 0;
}
