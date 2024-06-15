/*!
 * \file
 * \brief Заголовочный файл с описанием класса окна истории вычислений
 * Данный файл содержит в себе определение класса окна истории вычислений
*/

#ifndef STORYWINDOW_H
#define STORYWINDOW_H

#include <QDialog>
#include <QKeyEvent>
#include <deque>

namespace Ui {
class StoryWindow;
}

class StoryWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StoryWindow(QWidget *parent = nullptr);
    ~StoryWindow();

protected:
    void keyPressEvent(QKeyEvent *es) override;

private:
    Ui::StoryWindow *ui;

public slots:
    void slot(std::deque<double> story_first_num, std::deque<char> story_operation, std::deque<double> story_second_num, std::deque<double> story_equal_num);
};


#endif // STORYWINDOW_H
