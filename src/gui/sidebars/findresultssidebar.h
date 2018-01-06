// For license of this file, see <project-root-folder>/LICENSE.md.

#ifndef FINDRESULTSSIDEBAR_H
#define FINDRESULTSSIDEBAR_H

#include "gui/sidebars/dockwidget.h"

#include <QAbstractListModel>

#include "gui/texteditor.h"

class TextApplication;
class FindResultsModel;
class QTreeView;

class FindResultsSidebar : public DockWidget {
  Q_OBJECT

  public:
    explicit FindResultsSidebar(TextApplication* app, QWidget* parent = nullptr);

    virtual Qt::DockWidgetArea initialArea() const override;
    virtual bool initiallyVisible() const override;
    virtual int initialWidth() const override;

  public slots:
    virtual void load() override;

    void clear();
    void addResults(TextEditor* editor, const QList<QPair<int, int>> results);

  private:
    QTreeView* m_viewResults;
    TextApplication* m_textApp;
    FindResultsModel* m_model;
};

#endif // FINDRESULTSSIDEBAR_H
