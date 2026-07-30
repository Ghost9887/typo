#include "mead_terminal.h"
#include "mead_panel.h"
#include "mead_text.h"
#include "mead_border.h"

int main() 
{
    Mead::Terminal& term { Mead::Terminal::GetInstance() };

    Mead::Panel root { Mead::Panel::FullScreen() };

    Mead::Panel left { Mead::XPercent(50), Mead::YPercent(100), Mead::Location::LEFT };
    Mead::Panel right { Mead::XPercent(50), Mead::YPercent(100), Mead::Location::RIGHT };

    Mead::Text leftText { "Hello, World", Mead::Location::CENTER };
    Mead::Text rightText { "Hello, World", Mead::Location::CENTER };

    Mead::Border leftBorder { Mead::Border::Basic() };
    Mead::Border rightBorder { Mead::Border::Basic() };


    left.Add(leftBorder);
    left.Add(leftText);

    right.Add(rightBorder);
    right.Add(rightText);

    root.Add(left);
    root.Add(right);

    while (true)
    {
        root.Display();
        if (term.GetKey() == 'q') break;
    }

    return 0;
}
