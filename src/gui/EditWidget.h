/*
 *  Copyright (C) 2012 Felix Geyer <debfx@fobos.de>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 or (at your option)
 *  version 3 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KEEPASSX_EDITWIDGET_H
#define KEEPASSX_EDITWIDGET_H

#include <QScopedPointer>
#include <QtWidgets/QStyledItemDelegate>
#include <QStyledItemDelegate>

#include "gui/DialogyWidget.h"
#include "gui/MessageWidget.h"

class QLabel;

namespace Ui {
    class EditWidget;
}

class EditWidget : public DialogyWidget
{
    Q_OBJECT

public:
    explicit EditWidget(QWidget* parent = nullptr);
    ~EditWidget();

    void add(const QString& labelText, QWidget* widget);
    void setRowHidden(QWidget* widget, bool hide);
    void setCurrentRow(int index);
    void setHeadline(const QString& text);
    QLabel* headlineLabel();
    void setReadOnly(bool readOnly);
    bool readOnly() const;

protected:
    void showEvent(QShowEvent* event) override;

signals:
    void accepted();
    void rejected();

protected slots:
    void updateCategoryScrollButtons();
    void scrollCategoriesDown();
    void scrollCategoriesUp();
    void showMessage(const QString& text, MessageWidget::MessageType type);
    void hideMessage();

private:
    const QScopedPointer<Ui::EditWidget> m_ui;
    bool m_readOnly;

    Q_DISABLE_COPY(EditWidget)
};

#endif // KEEPASSX_EDITWIDGET_H
