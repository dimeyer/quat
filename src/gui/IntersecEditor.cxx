// generated by Fast Light User Interface Designer (fluid) version 1.0100

#include "IntersecEditor.h"
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
#include "ChildWindow.h"

inline void IntersecEditor::cb_scroll_i( Fl_Scrollbar* o, void* ) {
    setno( o->value() );
}
void IntersecEditor::cb_scroll( Fl_Scrollbar* o, void* v ) {
    ( ( IntersecEditor* )( o->parent()->user_data() ) )->cb_scroll_i( o, v );
}

inline void IntersecEditor::cb_nre_i( Fl_Value_Input* o, void* ) {
    cutbuf[7 * idx + 1] = o->value();
    checkValidity();
}
void IntersecEditor::cb_nre( Fl_Value_Input* o, void* v ) {
    ( ( IntersecEditor* )( o->parent()->parent()->user_data() ) )->cb_nre_i( o, v );
}

inline void IntersecEditor::cb_ni_i( Fl_Value_Input* o, void* ) {
    cutbuf[7 * idx + 2] = o->value();
    checkValidity();
}
void IntersecEditor::cb_ni( Fl_Value_Input* o, void* v ) {
    ( ( IntersecEditor* )( o->parent()->parent()->user_data() ) )->cb_ni_i( o, v );
}

inline void IntersecEditor::cb_nj_i( Fl_Value_Input* o, void* ) {
    cutbuf[7 * idx + 3] = o->value();
    checkValidity();
}
void IntersecEditor::cb_nj( Fl_Value_Input* o, void* v ) {
    ( ( IntersecEditor* )( o->parent()->parent()->user_data() ) )->cb_nj_i( o, v );
}

inline void IntersecEditor::cb_pre_i( Fl_Value_Input* o, void* ) {
    cutbuf[7 * idx + 4] = o->value();
}
void IntersecEditor::cb_pre( Fl_Value_Input* o, void* v ) {
    ( ( IntersecEditor* )( o->parent()->parent()->user_data() ) )->cb_pre_i( o, v );
}

inline void IntersecEditor::cb_pi_i( Fl_Value_Input* o, void* ) {
    cutbuf[7 * idx + 5] = o->value();
}
void IntersecEditor::cb_pi( Fl_Value_Input* o, void* v ) {
    ( ( IntersecEditor* )( o->parent()->parent()->user_data() ) )->cb_pi_i( o, v );
}

inline void IntersecEditor::cb_pj_i( Fl_Value_Input* o, void* ) {
    cutbuf[7 * idx + 6] = o->value();
}
void IntersecEditor::cb_pj( Fl_Value_Input* o, void* v ) {
    ( ( IntersecEditor* )( o->parent()->parent()->user_data() ) )->cb_pj_i( o, v );
}

inline void IntersecEditor::cb_add_i( Fl_Button*, void* ) {
    cutbuf.add();
    num = cutbuf.getnum();
    scroll->value( num - 1, 1, 0, num );
    setno( num - 1 );
}
void IntersecEditor::cb_add( Fl_Button* o, void* v ) {
    ( ( IntersecEditor* )( o->parent()->user_data() ) )->cb_add_i( o, v );
}

inline void IntersecEditor::cb_del_i( Fl_Button*, void* ) {
    cutbuf.del( idx );
    num = cutbuf.getnum();

    if( idx >= num && idx != 0 ) {
        idx = num - 1;
    }

    scroll->value( idx, 1, 0, num );
    setno( idx );
}
void IntersecEditor::cb_del( Fl_Button* o, void* v ) {
    ( ( IntersecEditor* )( o->parent()->user_data() ) )->cb_del_i( o, v );
}

IntersecEditor::IntersecEditor( int X, int Y, int W, int H, const char* label ) : Fl_Group( X, Y, W, H, label ), num( 0 ), idx( 0 ), _disabled( false ) {
    ChildWindow* w;
    {
        ChildWindow* o = win = new ChildWindow( 416, 216 );
        w = o;
        o->user_data( ( void* )( this ) );
        {
            Fl_Scrollbar* o = scroll = new Fl_Scrollbar( 10, 20, 20, 150, "Plane to edit" );
            o->tooltip( "Select the intersection plane to edit." );
            o->labelsize( 12 );
            o->callback( ( Fl_Callback* )cb_scroll );
            o->align( FL_ALIGN_TOP_LEFT );
            scroll->linesize( 1 );
            scroll->value( 0, 1, 0, 0 );
        }
        {
            Fl_Group* o = qspacebox = new Fl_Group( 120, 5, 270, 115, "QSpace coordinates" );
            o->tooltip( "All parameters in this box are measured in QSpace coordinates." );
            o->box( FL_EMBOSSED_BOX );
            o->labelsize( 12 );
            o->align( FL_ALIGN_TOP_LEFT | FL_ALIGN_INSIDE );
            o->end();
        }
        {
            Fl_Group* o = n = new Fl_Group( 130, 25, 110, 75 );
            o->tooltip( "Normal vector = stands perpendicular on the intersection plane." );
            o->labeltype( FL_NO_LABEL );
            {
                Fl_Value_Input* o = nre = new Fl_Value_Input( 130, 40, 110, 20, "Normal Vector" );
                o->tooltip( "Real part." );
                o->labelsize( 12 );
                o->minimum( -1e+20 );
                o->maximum( 1e+20 );
                o->textsize( 12 );
                o->callback( ( Fl_Callback* )cb_nre );
                o->align( FL_ALIGN_TOP_LEFT );
            }
            {
                Fl_Value_Input* o = ni = new Fl_Value_Input( 130, 60, 110, 20, "value:" );
                o->tooltip( "1st imaginary (i) part." );
                o->labeltype( FL_NO_LABEL );
                o->labelsize( 12 );
                o->minimum( -1e+20 );
                o->maximum( 1e+20 );
                o->textsize( 12 );
                o->callback( ( Fl_Callback* )cb_ni );
            }
            {
                Fl_Value_Input* o = nj = new Fl_Value_Input( 130, 80, 110, 20, "value:" );
                o->tooltip( "2nd imaginary (j) part." );
                o->labeltype( FL_NO_LABEL );
                o->labelsize( 12 );
                o->minimum( -1e+20 );
                o->maximum( 1e+20 );
                o->textsize( 12 );
                o->callback( ( Fl_Callback* )cb_nj );
            }
            o->end();
        }
        {
            Fl_Group* o = p = new Fl_Group( 270, 25, 110, 75 );
            o->tooltip( "Any point that lies on the desired plane." );
            o->labeltype( FL_NO_LABEL );
            {
                Fl_Value_Input* o = pre = new Fl_Value_Input( 270, 40, 110, 20, "Point to fix plane" );
                o->tooltip( "Real part." );
                o->labelsize( 12 );
                o->minimum( -1e+20 );
                o->maximum( 1e+20 );
                o->textsize( 12 );
                o->callback( ( Fl_Callback* )cb_pre );
                o->align( FL_ALIGN_TOP_LEFT );
            }
            {
                Fl_Value_Input* o = pi = new Fl_Value_Input( 270, 60, 110, 20, "value:" );
                o->tooltip( "1st imaginary (i) part." );
                o->labeltype( FL_NO_LABEL );
                o->labelsize( 12 );
                o->minimum( -1e+20 );
                o->maximum( 1e+20 );
                o->textsize( 12 );
                o->callback( ( Fl_Callback* )cb_pi );
            }
            {
                Fl_Value_Input* o = pj = new Fl_Value_Input( 270, 80, 110, 20, "value:" );
                o->tooltip( "2nd imaginary (j) part." );
                o->labeltype( FL_NO_LABEL );
                o->labelsize( 12 );
                o->minimum( -1e+20 );
                o->maximum( 1e+20 );
                o->textsize( 12 );
                o->callback( ( Fl_Callback* )cb_pj );
            }
            o->end();
        }
        {
            Fl_Button* o = add = new Fl_Button( 50, 60, 60, 20, "Add" );
            o->tooltip( "Add a new intersection plane." );
            o->labelsize( 12 );
            o->callback( ( Fl_Callback* )cb_add );
        }
        {
            Fl_Button* o = del = new Fl_Button( 50, 80, 60, 20, "Delete" );
            o->tooltip( "Delete the current plane." );
            o->labelsize( 12 );
            o->callback( ( Fl_Callback* )cb_del );
        }
        {
            Fl_Box* o = note = new Fl_Box( 130, 130, 230, 50, "The Normal Vector points to half-space\nin which the object will disappear." );
            o->labelsize( 12 );
            o->align( FL_ALIGN_LEFT | FL_ALIGN_INSIDE );
        }
        {
            Fl_Value_Output* o = planeno = new Fl_Value_Output( 50, 20, 30, 20 );
            o->labeltype( FL_NO_LABEL );
        }
        o->clear_border();
        o->end();
    }
    end(); // VERY IMPORTANT!
    win->position( X + 2, Y + 2 );
    // DON'T delete win in destructor (or elsewhere)
    // it's automatically deleted by Fl_Group
}

void IntersecEditor::set( const cutbuf_cpp& buf ) {
    cutbuf = buf;
    num = cutbuf.getnum();
    idx = 0;
    scroll->value( 0, 1, 0, num );
    setno( 0 );
    checkValidity();
}

void IntersecEditor::get( cutbuf_cpp& buf ) {
    buf = cutbuf;
}

void IntersecEditor::setno( int no ) {
    if( no < num || num == 0 ) {
        nre->value( cutbuf[no * 7 + 1] );
        ni->value( cutbuf[no * 7 + 2] );
        nj->value( cutbuf[no * 7 + 3] );
        pre->value( cutbuf[no * 7 + 4] );
        pi->value( cutbuf[no * 7 + 5] );
        pj->value( cutbuf[no * 7 + 6] );
        //	scroll->value(no, 1, 0, num-1);
        planeno->value( no + 1 );
        idx = no;
        //	if (scroll->value() != idx) scroll->value(no, 1, 0, num-1);
        checkValidity();
    }
}

void IntersecEditor::checkValidity() {
    const Fl_Color okc = FL_WHITE;
    const Fl_Color ndefc = FL_RED;
    Fl_Color nre_c = okc, ni_c = okc, nj_c = okc;

    if( nre->value() == 0.0 && ni->value() == 0.0 && nj->value() == 0.0 ) {
        nre_c = ndefc;
        ni_c = ndefc;
        nj_c = ndefc;
    }

    if( nre->color() != nre_c ) {
        nre->color( nre_c );
        nre->redraw();
    }

    if( ni->color() != ni_c ) {
        ni->color( ni_c );
        ni->redraw();
    }

    if( nj->color() != nj_c ) {
        nj->color( nj_c );
        nj->redraw();
    }

    if( num == 0 && scroll->active() ) {
        qspacebox->hide();
        n->hide();
        p->hide();
        note->hide();
        planeno->hide();
        scroll->deactivate();
        del->deactivate();
    }

    if( num != 0 && !scroll->active() ) {
        qspacebox->show();
        n->show();
        p->show();
        note->show();
        planeno->show();
        scroll->activate();
    }

    if( num == 20 && add->active() ) {
        add->deactivate();
    }

    if( num != 20 && !add->active() && !_disabled ) {
        add->activate();
    }

    if( num == 0 && del->active() ) {
        del->deactivate();
    }

    if( num != 0 && !del->active() && !_disabled ) {
        del->activate();
    }

    return;
}

void IntersecEditor::deactiv() {
    n->deactivate();
    p->deactivate();
    add->deactivate();
    del->deactivate();
    _disabled = true;
}
