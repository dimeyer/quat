// generated by Fast Light User Interface Designer (fluid) version 1.0100

#include "ColorEditor.h"
// Quat - A 3D fractal generation program
// Copyright (C) 1997-2000 Dirk Meyer
// (email: dirk.meyer@studserv.uni-stuttgart.de)
// mail:  Dirk Meyer
//        Marbacher Weg 29
//        D-71334 Waiblingen
//        Germany
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <FL/Fl_Color_Chooser.H>
#include "ColorPreview.h"
#include "ColorClipboard.h"
#include "ChildWindow.h"

inline void ColorEditor::cb_add_i( Fl_Button*, void* ) {
    CP->add();
}
void ColorEditor::cb_add( Fl_Button* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_add_i( o, v );
}

inline void ColorEditor::cb_del_i( Fl_Button*, void* ) {
    CP->del();
}
void ColorEditor::cb_del( Fl_Button* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_del_i( o, v );
}

inline void ColorEditor::cb_weight_i( Fl_Value_Input* o, void* ) {
    CP->weight( CP->current(), o->value() );
}
void ColorEditor::cb_weight( Fl_Value_Input* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_weight_i( o, v );
}

inline void ColorEditor::cb_red1_i( Fl_Value_Input* o, void* ) {
    CP->red1( CP->current(), o->value() );
}
void ColorEditor::cb_red1( Fl_Value_Input* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_red1_i( o, v );
}

inline void ColorEditor::cb_green1_i( Fl_Value_Input* o, void* ) {
    CP->green1( CP->current(), o->value() );
}
void ColorEditor::cb_green1( Fl_Value_Input* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_green1_i( o, v );
}

inline void ColorEditor::cb_blue1_i( Fl_Value_Input* o, void* ) {
    CP->blue1( CP->current(), o->value() );
}
void ColorEditor::cb_blue1( Fl_Value_Input* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_blue1_i( o, v );
}

inline void ColorEditor::cb_button_sel1_i( Fl_Button*, void* ) {
    {
        double r = red1->value();
        double g = green1->value();
        double b = blue1->value();

        if( fl_color_chooser( "Select Color 1", r, g, b ) ) {
            red1->value( r );
            green1->value( g );
            blue1->value( b );
            red1->do_callback();
            green1->do_callback();
            blue1->do_callback();
        }
    };
}
void ColorEditor::cb_button_sel1( Fl_Button* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_button_sel1_i( o, v );
}

inline void ColorEditor::cb_button_copy1_i( Fl_Button*, void* ) {
    clip->Set( red1->value(), green1->value(), blue1->value() );
    clip->redraw();
}
void ColorEditor::cb_button_copy1( Fl_Button* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_button_copy1_i( o, v );
}

inline void ColorEditor::cb_button_paste1_i( Fl_Button*, void* ) {
    red1->value( clip->GetRed() );
    green1->value( clip->GetGreen() );
    blue1->value( clip->GetBlue() );
    red1->do_callback();
    green1->do_callback();
    blue1->do_callback();
}
void ColorEditor::cb_button_paste1( Fl_Button* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_button_paste1_i( o, v );
}

inline void ColorEditor::cb_red2_i( Fl_Value_Input* o, void* ) {
    CP->red2( CP->current(), o->value() );
}
void ColorEditor::cb_red2( Fl_Value_Input* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_red2_i( o, v );
}

inline void ColorEditor::cb_green2_i( Fl_Value_Input* o, void* ) {
    CP->green2( CP->current(), o->value() );
}
void ColorEditor::cb_green2( Fl_Value_Input* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_green2_i( o, v );
}

inline void ColorEditor::cb_blue2_i( Fl_Value_Input* o, void* ) {
    CP->blue2( CP->current(), o->value() );
}
void ColorEditor::cb_blue2( Fl_Value_Input* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_blue2_i( o, v );
}

inline void ColorEditor::cb_button_sel2_i( Fl_Button*, void* ) {
    {
        double r = red2->value();
        double g = green2->value();
        double b = blue2->value();

        if( fl_color_chooser( "Select Color 2", r, g, b ) ) {
            red2->value( r );
            green2->value( g );
            blue2->value( b );
            red2->do_callback();
            green2->do_callback();
            blue2->do_callback();
        }
    };
}
void ColorEditor::cb_button_sel2( Fl_Button* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_button_sel2_i( o, v );
}

inline void ColorEditor::cb_button_copy2_i( Fl_Button*, void* ) {
    clip->Set( red2->value(), green2->value(), blue2->value() );
    clip->redraw();
}
void ColorEditor::cb_button_copy2( Fl_Button* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_button_copy2_i( o, v );
}

inline void ColorEditor::cb_button_paste2_i( Fl_Button*, void* ) {
    red2->value( clip->GetRed() );
    green2->value( clip->GetGreen() );
    blue2->value( clip->GetBlue() );
    red2->do_callback();
    green2->do_callback();
    blue2->do_callback();
}
void ColorEditor::cb_button_paste2( Fl_Button* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_button_paste2_i( o, v );
}

inline void ColorEditor::cb_0_i( Fl_Menu_* o, void* ) {
    ColorFormula->value( o->text() );
}
void ColorEditor::cb_0( Fl_Menu_* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_0_i( o, v );
}

inline void ColorEditor::cb_01_i( Fl_Menu_* o, void* ) {
    ColorFormula->value( o->text() );
}
void ColorEditor::cb_01( Fl_Menu_* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_01_i( o, v );
}

inline void ColorEditor::cb_02_i( Fl_Menu_* o, void* ) {
    ColorFormula->value( o->text() );
}
void ColorEditor::cb_02( Fl_Menu_* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_02_i( o, v );
}

inline void ColorEditor::cb_03_i( Fl_Menu_* o, void* ) {
    ColorFormula->value( o->text() );
}
void ColorEditor::cb_03( Fl_Menu_* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_03_i( o, v );
}

inline void ColorEditor::cb_04_i( Fl_Menu_* o, void* ) {
    ColorFormula->value( o->text() );
}
void ColorEditor::cb_04( Fl_Menu_* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_04_i( o, v );
}

inline void ColorEditor::cb_x_i( Fl_Menu_* o, void* ) {
    ColorFormula->value( o->text() );
}
void ColorEditor::cb_x( Fl_Menu_* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_x_i( o, v );
}

inline void ColorEditor::cb_sin_i( Fl_Menu_* o, void* ) {
    ColorFormula->value( o->text() );
}
void ColorEditor::cb_sin( Fl_Menu_* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_sin_i( o, v );
}

inline void ColorEditor::cb_y_i( Fl_Menu_* o, void* ) {
    ColorFormula->value( o->text() );
}
void ColorEditor::cb_y( Fl_Menu_* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_y_i( o, v );
}

inline void ColorEditor::cb_sqrt_i( Fl_Menu_* o, void* ) {
    ColorFormula->value( o->text() );
}
void ColorEditor::cb_sqrt( Fl_Menu_* o, void* v ) {
    ( ( ColorEditor* )( o->parent()->user_data() ) )->cb_sqrt_i( o, v );
}

Fl_Menu_Item ColorEditor::menu_choice_formula[] = {
    {" These are only examples.", 0,  0, 0, 1, 0, 0, 12, 72},
    {" You can also enter your own formula!", 0,  0, 0, 1, 0, 0, 12, 72},
    {" 0", 0, ( Fl_Callback* )ColorEditor::cb_0, 0, 0, 0, 0, 12, 0},
    {" 0.36*x-0.5       # linear in x-dir", 0, ( Fl_Callback* )ColorEditor::cb_01, 0, 0, 0, 0, 12, 0},
    {" 0.48*y-0.5      # linear in y-dir.", 0, ( Fl_Callback* )ColorEditor::cb_02, 0, 0, 0, 0, 12, 0},
    {" 0.25*z-0.5      # linear in z-dir.", 0, ( Fl_Callback* )ColorEditor::cb_03, 0, 0, 0, 0, 12, 0},
    {" 0.7*sqrt(x^2+y^2+z^2)     # spherical", 0, ( Fl_Callback* )ColorEditor::cb_04, 0, 0, 0, 0, 12, 0},
    {" x+y     # diagonal striped", 0, ( Fl_Callback* )ColorEditor::cb_x, 0, 0, 0, 0, 12, 0},
    {" (sin(7*x)+sin(7*y)+sin(7*z)+3)/6  # big speckles", 0, ( Fl_Callback* )ColorEditor::cb_sin, 0, 0, 0, 0, 12, 0},
    {" y+0.2*sin(15*x)    # spikes", 0, ( Fl_Callback* )ColorEditor::cb_y, 0, 0, 0, 0, 12, 0},
    {
        " sqrt((orbite(5)-x)^2+(orbitj(5)-y)^2+(orbitk(5)-z)^2+(orbitl(5)-orbitl(0))^2\
)", 0, ( Fl_Callback* )ColorEditor::cb_sqrt, 0, 0, 0, 0, 12, 0
    },
    {0}
};

ColorEditor::ColorEditor( int X, int Y, int W, int H, const char* label ) : Fl_Group( X, Y, W, H, label ) {
    ChildWindow* w;
    {
        ChildWindow* o = win = new ChildWindow( 416, 216 );
        w = o;
        o->user_data( ( void* )( this ) );
        {
            Fl_Group* o = new Fl_Group( 10, 50, 100, 90, "Range" );
            o->tooltip( "A color range begins with color 1 and fades smoothly into color 2." );
            o->box( FL_EMBOSSED_FRAME );
            o->labelsize( 12 );
            o->align( FL_ALIGN_TOP_LEFT | FL_ALIGN_INSIDE );
            o->end();
        }
        {
            Fl_Group* o = new Fl_Group( 110, 50, 150, 90, "Color 1" );
            o->tooltip( "Start color of the selected color range." );
            o->box( FL_EMBOSSED_FRAME );
            o->labelsize( 12 );
            o->align( FL_ALIGN_TOP_LEFT | FL_ALIGN_INSIDE );
            o->end();
        }
        {
            Fl_Group* o = new Fl_Group( 260, 50, 150, 90, "Color 2" );
            o->tooltip( "End color of the selected color range." );
            o->box( FL_EMBOSSED_FRAME );
            o->labelsize( 12 );
            o->align( FL_ALIGN_TOP_LEFT | FL_ALIGN_INSIDE );
            o->end();
        }
        {
            ColorPreview* o = CP = new ColorPreview( 10, 5, 370, 20, "label" );
            o->tooltip( "Select the color range to edit." );
            o->box( FL_UP_BOX );
            o->labeltype( FL_NO_LABEL );
            o->labelsize( 12 );
        }
        {
            ColorClipboard* o = clip = new ColorClipboard( 390, 5, 20, 20, "label" );
            o->tooltip( "Displays the color currently in clipboard." );
            o->box( FL_DOWN_BOX );
            o->labeltype( FL_NO_LABEL );
            o->labelsize( 12 );
            o->align( FL_ALIGN_CENTER | FL_ALIGN_INSIDE );
        }
        {
            Fl_Box* o = new Fl_Box( 30, 25, 20, 10, "0" );
            o->box( FL_FLAT_BOX );
            o->labelsize( 10 );
        }
        {
            Fl_Box* o = new Fl_Box( 340, 25, 20, 10, "1" );
            o->box( FL_FLAT_BOX );
            o->labelsize( 10 );
        }
        {
            Fl_Output* o = range = new Fl_Output( 180, 25, 40, 15 );
            o->tooltip( "Currently selected color range / number of color ranges in palette." );
            o->textsize( 11 );
        }
        {
            Fl_Button* o = add = new Fl_Button( 20, 70, 40, 20, "Add" );
            o->tooltip( "Insert a new color range before the selected one." );
            o->labelsize( 12 );
            o->callback( ( Fl_Callback* )cb_add );
        }
        {
            Fl_Button* o = del = new Fl_Button( 60, 70, 40, 20, "Del" );
            o->tooltip( "Delete the selected color range." );
            o->labelsize( 12 );
            o->callback( ( Fl_Callback* )cb_del );
            o->deactivate();
        }
        {
            Fl_Value_Input* o = weight = new Fl_Value_Input( 20, 110, 80, 20, "Weighting" );
            o->tooltip( "Size of the selected color range in the palette." );
            o->labelsize( 12 );
            o->minimum( 1e-05 );
            o->maximum( 100 );
            o->textsize( 12 );
            o->callback( ( Fl_Callback* )cb_weight );
            o->align( FL_ALIGN_TOP_LEFT );
        }
        {
            Fl_Value_Input* o = red1 = new Fl_Value_Input( 130, 70, 80, 20, "R" );
            o->tooltip( "Red" );
            o->labelsize( 12 );
            o->textsize( 12 );
            o->callback( ( Fl_Callback* )cb_red1 );
        }
        {
            Fl_Value_Input* o = green1 = new Fl_Value_Input( 130, 90, 80, 20, "G" );
            o->tooltip( "Green" );
            o->labelsize( 12 );
            o->textsize( 12 );
            o->callback( ( Fl_Callback* )cb_green1 );
        }
        {
            Fl_Value_Input* o = blue1 = new Fl_Value_Input( 130, 110, 80, 20, "B" );
            o->tooltip( "Blue" );
            o->labelsize( 12 );
            o->textsize( 12 );
            o->callback( ( Fl_Callback* )cb_blue1 );
        }
        {
            Fl_Button* o = button_sel1 = new Fl_Button( 210, 70, 40, 20, "Sel" );
            o->tooltip( "Graphically select color 1." );
            o->labelsize( 12 );
            o->callback( ( Fl_Callback* )cb_button_sel1 );
        }
        {
            Fl_Button* o = button_copy1 = new Fl_Button( 210, 90, 40, 20, "Copy" );
            o->tooltip( "Copy color 1 to clipboard." );
            o->labelsize( 12 );
            o->callback( ( Fl_Callback* )cb_button_copy1 );
        }
        {
            Fl_Button* o = button_paste1 = new Fl_Button( 210, 110, 40, 20, "Paste" );
            o->tooltip( "Copy clipboard to color 1." );
            o->labelsize( 12 );
            o->callback( ( Fl_Callback* )cb_button_paste1 );
        }
        {
            Fl_Value_Input* o = red2 = new Fl_Value_Input( 280, 70, 80, 20, "R" );
            o->tooltip( "Red" );
            o->labelsize( 12 );
            o->textsize( 12 );
            o->callback( ( Fl_Callback* )cb_red2 );
        }
        {
            Fl_Value_Input* o = green2 = new Fl_Value_Input( 280, 90, 80, 20, "G" );
            o->tooltip( "Green" );
            o->labelsize( 12 );
            o->textsize( 12 );
            o->callback( ( Fl_Callback* )cb_green2 );
        }
        {
            Fl_Value_Input* o = blue2 = new Fl_Value_Input( 280, 110, 80, 20, "B" );
            o->tooltip( "Blue" );
            o->labelsize( 12 );
            o->textsize( 12 );
            o->callback( ( Fl_Callback* )cb_blue2 );
        }
        {
            Fl_Button* o = button_sel2 = new Fl_Button( 360, 70, 40, 20, "Sel" );
            o->tooltip( "Graphically select color 2." );
            o->labelsize( 12 );
            o->callback( ( Fl_Callback* )cb_button_sel2 );
        }
        {
            Fl_Button* o = button_copy2 = new Fl_Button( 360, 90, 40, 20, "Copy" );
            o->tooltip( "Copy color 2 to clipboard." );
            o->labelsize( 12 );
            o->callback( ( Fl_Callback* )cb_button_copy2 );
        }
        {
            Fl_Button* o = button_paste2 = new Fl_Button( 360, 110, 40, 20, "Paste" );
            o->tooltip( "Copy clipboard to color 2." );
            o->labelsize( 12 );
            o->callback( ( Fl_Callback* )cb_button_paste2 );
        }
        {
            Fl_Choice* o = choice_formula = new Fl_Choice( 10, 190, 20, 20, "Color Formula" );
            o->tooltip( "Click here for example formulas." );
            o->down_box( FL_DOWN_BOX );
            o->labelsize( 12 );
            o->textsize( 12 );
            o->align( FL_ALIGN_TOP_LEFT );
            o->menu( menu_choice_formula );
        }
        {
            Fl_Input* o = ColorFormula = new Fl_Input( 30, 190, 380, 20, "Color Formula" );
            o->tooltip( "The result of a color formula is an index into the palette.\nSo you can estab\
lish a connection between points\nin space and colors" );
            o->labeltype( FL_NO_LABEL );
            o->labelsize( 12 );
            o->textsize( 12 );
            o->align( FL_ALIGN_TOP_LEFT );
        }
        o->clear_border();
        o->end();
    }
    CP->SetInputs( add, del, weight, red1, green1, blue1, red2, green2, blue2, range );
    end(); // VERY IMPORTANT!
    win->position( X + 2, Y + 2 );
    // DON'T delete win in destructor (or elsewhere)
    // it's automatically deleted by Fl_Group
}

void ColorEditor::set( const realpal_cpp& p, const colscheme_cpp& scheme ) {
    CP->SetPal( p );
    ColorFormula->value( reinterpret_cast<const char*>( &scheme ) );

    return;
}

void ColorEditor::get( realpal_cpp& p, colscheme_cpp& scheme ) {
    CP->GetPal( p );
    strcpy( scheme, ColorFormula->value() );
    return;
}

void ColorEditor::deactiv() {
    add->deactivate();
    del->deactivate();
    weight->deactivate();
    button_sel1->deactivate();
    button_copy1->deactivate();
    button_paste1->deactivate();
    red1->deactivate();
    green1->deactivate();
    blue1->deactivate();
    button_sel2->deactivate();
    button_copy2->deactivate();
    button_paste2->deactivate();
    red2->deactivate();
    green2->deactivate();
    blue2->deactivate();
    choice_formula->deactivate();
    ColorFormula->deactivate();
}
