#include "mead_terminal.h"
#include "mead_panel.h"
#include "mead_text.h"
#include "mead_border.h"

int main() 
{
    Mead::Terminal& term { Mead::Terminal::GetInstance() };

    Mead::Panel root { Mead::Panel::FullScreen() };

    Mead::Panel left { Mead::WidthPercent(50), Mead::HeightPercent(100), Mead::Anchor::LEFT };

    Mead::Panel right { Mead::WidthPercent(50), Mead::HeightPercent(100), Mead::Anchor::RIGHT };

    Mead::Text leftText { "Hello, World", Mead::Allignment::CENTER };
    Mead::Text rightText { "Hello, World", Mead::Allignment::CENTER };

    Mead::Text title { "Title", Mead::Allignment::TITLE_CENTER };

    Mead::Border border { Mead::Border::Round() };

    left.Add(border);
    left.Add(leftText);
    left.Add(title);

    right.Add(border);
    right.Add(rightText);

    root.Add(left);
    root.Add(right);

    term.AddPanel(root);

    while (true)
    {
        term.Render(root);
        if (term.GetKey() == 'q') break;
    }

    return 0;
}
