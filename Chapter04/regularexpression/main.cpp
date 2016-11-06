#include <QApplication>
#include <QLineEdit>
#include <QRegularExpression>
#include <QtDebug>
#include <QMessageBox>

int main(int argc, char **argv) {
    QApplication app(argc, argv);
    QLineEdit le;
    le.show();
    QRegularExpression regex("\\A[1-9][0-9]{0,2}[ ]?(mg|g|kg)\\z");
    regex.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    QObject::connect(&le, &QLineEdit::returnPressed, [&]() {
        QRegularExpressionMatch result = regex.match(le.text());
        if(result.hasMatch()) {
            QMessageBox::information(&le, "Input", "Input matches the regular expression");
        } else {
            QMessageBox::warning(&le, "Input", "Input doesn't match the regular expression");
        }
    });
    return app.exec();
}
