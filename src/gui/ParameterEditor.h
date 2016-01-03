// generated by Fast Light User Interface Designer (fluid) version 1.0100

#ifndef ParameterEditor_h
#define ParameterEditor_h
#include <FL/Fl.H>
class ObjectEditor;
class ViewEditor;
class ColorEditor;
class IntersecEditor;
class OtherEditor;
class JuliaPreview;
class ViewSelector;
#include "structs.h"
class dragWindow;
#include <FL/Fl_Window.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Value_Slider.H>

class ParameterEditor {
    public:
        ParameterEditor() ;
        Fl_Window* dialog;
        Fl_Tabs* tabs;
        ObjectEditor* Object;
        ViewEditor* View;
        ColorEditor* Color;
        IntersecEditor* Intersection;
        OtherEditor* Other;
        Fl_Box* info;
        Fl_Return_Button* ok_button;
    private:
        inline void cb_ok_button_i( Fl_Return_Button*, void* );
        static void cb_ok_button( Fl_Return_Button*, void* );
    public:
        Fl_Button* cancel_button;
    private:
        inline void cb_cancel_button_i( Fl_Button*, void* );
        static void cb_cancel_button( Fl_Button*, void* );
    public:
        Fl_Button* button_reset;
    private:
        inline void cb_button_reset_i( Fl_Button*, void* );
        static void cb_button_reset( Fl_Button*, void* );
    public:
        Fl_Button* button_import;
    private:
        inline void cb_button_import_i( Fl_Button*, void* );
        static void cb_button_import( Fl_Button*, void* );
    public:
        Fl_Button* button_read;
    private:
        inline void cb_button_read_i( Fl_Button*, void* );
        static void cb_button_read( Fl_Button*, void* );
        inline void cb_Write_i( Fl_Button*, void* );
        static void cb_Write( Fl_Button*, void* );
    public:
        Fl_Light_Button* own;
        Fl_Light_Button* stereo;
        Fl_Light_Button* button_show;
    private:
        inline void cb_button_show_i( Fl_Light_Button*, void* );
        static void cb_button_show( Fl_Light_Button*, void* );
    public:
        Fl_Button* DoPreview;
    private:
        inline void cb_DoPreview_i( Fl_Button*, void* );
        static void cb_DoPreview( Fl_Button*, void* );
    public:
        Fl_Value_Slider* preview_size;
        ViewSelector* vsbeside;
        ViewSelector* vsfront;
        ViewSelector* vsabove;
        dragWindow* window_preview;
        JuliaPreview* Preview;
        int run();
        void set( const frac_cpp& f, const view_cpp& v, const realpal_cpp& r, const colscheme_cpp& colscheme, const cutbuf_cpp& cutbuf );
        void get( frac_cpp& f, view_cpp& v, realpal_cpp& r, colscheme_cpp& colscheme, cutbuf_cpp& cutbuf );
        void SetState( int state );
        ~ParameterEditor();
        void calcPreview();
    private:
        int _state;
        int _result;
};
#endif
