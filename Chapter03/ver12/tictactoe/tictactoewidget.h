#ifndef TICTACTOEWIDGET_H
#define TICTACTOEWIDGET_H

#include <QWidget>
class QPushButton;

class TicTacToeWidget : public QWidget
{
    Q_OBJECT
    Q_ENUMS(Player)
    Q_PROPERTY(Player currentPlayer READ currentPlayer
                                    WRITE setCurrentPlayer
                                    NOTIFY currentPlayerChanged)

public:
    enum Player {
        Invalid, Player1, Player2, Draw
    };

    TicTacToeWidget(QWidget *parent = 0);
    ~TicTacToeWidget();
    void initNewGame();
    Player currentPlayer() const { return m_currentPlayer; }
    void setCurrentPlayer(Player p) {
        if(m_currentPlayer == p) return;
        m_currentPlayer = p;
        emit currentPlayerChanged(p);
    }

    Player checkWinCondition(int row, int column) const;

public slots:
    void handleButtonClick(int index);

signals:
    void currentPlayerChanged(Player);
    void gameOver(TicTacToeWidget::Player);

private:
    QList<QPushButton*> board;
    Player m_currentPlayer;
    void setupBoard();
};

#endif // TICTACTOEWIDGET_H
