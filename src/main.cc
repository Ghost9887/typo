#include "mead_terminal.h"
#include "mead_panel.h"
#include "mead_text.h"
#include "mead_border.h"
#include <iostream>

int main() 
{
    Mead::Terminal& term = Mead::Terminal::GetInstance();

    Mead::Panel root { Mead::Panel::FullScreen() };
    Mead::Panel left { Mead::WidthPercent(50), Mead::HeightPercent(100), Mead::Anchor::LEFT };
    Mead::Panel right { Mead::WidthPercent(50), Mead::HeightPercent(100), Mead::Anchor::RIGHT };
    Mead::Panel center { Mead::WidthPercent(50), Mead::HeightPercent(50), Mead::Anchor::CENTER };

    Mead::Text panel1 { "Hello, World", Mead::Alignment::TOP_LEFT };
    Mead::Text panel2 { "Hello, World", Mead::Alignment::TOP_LEFT };
    Mead::Text panel3 { "Hello, World", Mead::Alignment::TOP_LEFT };

    Mead::Text title { "Title", Mead::Alignment::TITLE_CENTER };
    title.SetForegroundColor(Mead::RGB::Blue());

    Mead::Border border0 { Mead::Border::Round() };

    Mead::Border border1 { Mead::Border::Round() };
    border1.SetColor(Mead::RGB::Blue());

    Mead::Border border2 { Mead::Border::Round() };
    border2.SetColor(Mead::RGB::Red());

    Mead::Border border3 { Mead::Border::Round() };
    border3.SetColor(Mead::RGB::Green());

    left.Add(border1);
    left.Add(panel1);
    left.Add(title);

    right.Add(border2);
    right.Add(panel2);
    
    center.Add(border3);
    center.Add(panel3);

    root.Add(left);
    root.Add(right);
    root.Add(center);

    term.AddPanel(root);

    while (true)
    {
        term.RenderAll();
        if (term.GetKey() == 'q') break;
    }

    return 0;
}
