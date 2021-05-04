// generated by Fast Light User Interface Designer (fluid) version 2.0100

#include <fltk/HelpDialog.h>
// Code for //\n// "$Id: HelpDialog.fl 4721 2005-12-19 16:52:...
#include <fltk/string.h>
#include <fltk/ask.h>
using namespace fltk;

inline void HelpDialog::cb_view__i(fltk::HelpView*, void*) {
  if (view_->filename())
  {
    if (view_->changed())
    {
      index_ ++;

      view_->clear_changed ();
      if (index_ >= 100)
      {
	memmove(line_, line_ + 10, sizeof(line_[0]) * 90);
	memmove(file_, file_ + 10, sizeof(file_[0]) * 90);
	index_ -= 10;
      }

      max_ = index_;

      strlcpy(file_[index_], view_->filename(),sizeof(file_[0]));
      line_[index_] = view_->topline();

      if (index_ > 0)
	back_->activate();
      else
	back_->deactivate();

      forward_->deactivate();
      window_->label(view_->title());
    }
    else // if ! view_->changed()
    {
      strlcpy(file_[index_], view_->filename(), sizeof(file_[0]));
      line_[index_] = view_->topline();
    }
  } else { // if ! view_->filename()
    index_ = 0; // hitting an internal page will disable the back/fwd buffer
    file_[index_][0] = 0; // unnamed internal page
    line_[index_] = view_->topline();
    back_->deactivate();
    forward_->deactivate();
  }
;}
void HelpDialog::cb_view_(fltk::HelpView* o, void* v) {
  ((HelpDialog*)(o->parent()->user_data()))->cb_view__i(o,v);
}

inline void HelpDialog::cb_Close_i(fltk::Button*, void*) {
  window_->hide();
}
void HelpDialog::cb_Close(fltk::Button* o, void* v) {
  ((HelpDialog*)(o->parent()->parent()->user_data()))->cb_Close_i(o,v);
}

inline void HelpDialog::cb_back__i(fltk::Button*, void*) {
  if (index_ > 0)
    index_ --;

  if (index_ == 0)
    back_->deactivate();

  forward_->activate();

  int l = line_[index_];

  if (strcmp(view_->filename(), file_[index_]) != 0)
    view_->load(file_[index_]);

  view_->topline(l);
}
void HelpDialog::cb_back_(fltk::Button* o, void* v) {
  ((HelpDialog*)(o->parent()->parent()->user_data()))->cb_back__i(o,v);
}

inline void HelpDialog::cb_forward__i(fltk::Button*, void*) {
  if (index_ < max_)
    index_ ++;

  if (index_ >= max_)
    forward_->deactivate();

  back_->activate();

  int l = view_->topline();

  if (strcmp(view_->filename(), file_[index_]) != 0)
    view_->load(file_[index_]);

  view_->topline(l);
}
void HelpDialog::cb_forward_(fltk::Button* o, void* v) {
  ((HelpDialog*)(o->parent()->parent()->user_data()))->cb_forward__i(o,v);
}

inline void HelpDialog::cb_smaller__i(fltk::Button*, void*) {
  if (view_->textsize() > 8)
    view_->textsize(view_->textsize() - 2);

  if (view_->textsize() <= 8)
    smaller_->deactivate();
  larger_->activate();
}
void HelpDialog::cb_smaller_(fltk::Button* o, void* v) {
  ((HelpDialog*)(o->parent()->parent()->user_data()))->cb_smaller__i(o,v);
}

inline void HelpDialog::cb_larger__i(fltk::Button*, void*) {
  if (view_->textsize() < 18)
    view_->textsize(view_->textsize() + 2);

  if (view_->textsize() >= 18)
    larger_->deactivate();
  smaller_->activate();
}
void HelpDialog::cb_larger_(fltk::Button* o, void* v) {
  ((HelpDialog*)(o->parent()->parent()->user_data()))->cb_larger__i(o,v);
}

inline void HelpDialog::cb_find__i(fltk::Input*, void*) {
  find_pos_ = view_->find(find_->text(), find_pos_);
}
void HelpDialog::cb_find_(fltk::Input* o, void* v) {
  ((HelpDialog*)(o->parent()->parent()->parent()->user_data()))->cb_find__i(o,v);
}

HelpDialog::HelpDialog() {
   {fltk::DoubleBufferWindow* o = window_ = new fltk::DoubleBufferWindow(530, 385, "Help Dialog");
    o->type(241);
    o->user_data((void*)(this));
    o->begin();
     {fltk::HelpView* o = view_ = new fltk::HelpView(10, 10, 505, 330);
      o->box(fltk::DOWN_BOX);
      o->selection_color((fltk::Color)15);
      o->callback((fltk::Callback*)cb_view_);
    }
     {fltk::Group* o = new fltk::Group(10, 348, 510, 27);
      o->begin();
       {fltk::Button* o = new fltk::Button(446, 2, 64, 25, "Close");
	o->callback((fltk::Callback*)cb_Close);
	o->label("Close");
      }
       {fltk::Button* o = back_ = new fltk::Button(376, 2, 25, 25, "@<-");
	o->labelcolor((fltk::Color)2);
	o->shortcut(0xff51);
	o->callback((fltk::Callback*)cb_back_);
	o->tooltip("Show the previous help page.");
      }
       {fltk::Button* o = forward_ = new fltk::Button(411, 2, 25, 25, "@->");
	o->labelcolor((fltk::Color)2);
	o->shortcut(0xff53);
	o->callback((fltk::Callback*)cb_forward_);
	o->tooltip("Show the next help page.");
      }
       {fltk::Button* o = smaller_ = new fltk::Button(306, 2, 25, 25, "F");
	o->labelfont(fltk::HELVETICA_BOLD);
	o->labelsize(10);
	o->callback((fltk::Callback*)cb_smaller_);
	o->tooltip("Make the help text smaller.");
      }
       {fltk::Button* o = larger_ = new fltk::Button(341, 2, 25, 25, "F");
	o->labelfont(fltk::HELVETICA_BOLD);
	o->labelsize(16);
	o->callback((fltk::Callback*)cb_larger_);
	o->tooltip("Make the help text larger.");
      }
       {fltk::Group* o = new fltk::Group(0, 2, 296, 25);
	o->box(fltk::DOWN_BOX);
	o->color((fltk::Color)7);
	o->begin();
	 {fltk::Input* o = find_ = new fltk::Input(25, 2, 268, 21, "@search");
	  o->box(fltk::FLAT_BOX);
	  o->labelsize(13);
	  o->callback((fltk::Callback*)cb_find_);
	  o->when(fltk::WHEN_ENTER_KEY_ALWAYS);
	  fltk::Group::current()->resizable(o);
	  o->tooltip("find text in document");
	}
	o->end();
	fltk::Group::current()->resizable(o);
      }
      o->end();
      fltk::Group::current()->resizable(o);
    }
    o->end();
  }
  back_->deactivate();
  forward_->deactivate();

  index_    = -1;
  max_      = 0;
  find_pos_ = 0;
  window_->resizable(view_);
  fltk::register_images();
}

HelpDialog::~HelpDialog() {
  delete window_;
}

int HelpDialog::h() {
  return (window_->h());
}

void HelpDialog::hide() {
  window_->hide();
}

void HelpDialog::load(const char *f) {
  view_->set_changed();
  view_->load(f);
  window_->label(view_->title());
}

void HelpDialog::position(int xx, int yy) {
  window_->position(xx, yy);
}

void HelpDialog::resize(int xx, int yy, int ww, int hh) {
  window_->resize(xx, yy, ww, hh);
}

void HelpDialog::show() {
  window_->show();
}

void HelpDialog::show(int argc, char **argv) {
  window_->show(argc, argv);
}

void HelpDialog::textsize(uchar s) {
  view_->textsize(s);

  if (s <= 8)
    smaller_->deactivate();
  else
    smaller_->activate();

  if (s >= 18)
    larger_->deactivate();
  else
    larger_->activate();
}

uchar HelpDialog::textsize() {
  return (view_->textsize());
}

void HelpDialog::topline(const char *n) {
  view_->topline(n);
}

void HelpDialog::topline(int n) {
  view_->topline(n);
}

void HelpDialog::value(const char *f) {
  view_->set_changed();
  view_->value(f);
  window_->label(view_->title());
}

const char * HelpDialog::value() const {
  return view_->value();
}

int HelpDialog::visible() {
  return (window_->visible());
}

int HelpDialog::w() {
  return (window_->w());
}

int HelpDialog::x() {
  return (window_->x());
}

int HelpDialog::y() {
  return (window_->y());
}
// Code for //\n// End of "$Id: HelpDialog.fl 4721 2005-12-19...
