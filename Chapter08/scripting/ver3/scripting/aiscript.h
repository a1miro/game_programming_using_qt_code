#ifndef AISCRIPT_H
#define AISCRIPT_H

#include <QScriptProgram>
#include <QScriptValue>

class AIScript {
public:
  QScriptProgram read(const QString &fileName);
  bool evaluate(const QScriptProgram &program, QScriptEngine *engine);


  QScriptValue initFunction;
  QScriptValue heartbeatFunction;
  QScriptValue defendFunction;
  void initialize(QScriptEngine *engine);
private:
  QScriptValue m_thisObject;
};

#endif // AISCRIPT_H
