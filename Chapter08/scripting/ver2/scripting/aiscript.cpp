#include "aiscript.h"
#include <QFile>
#include <QScriptContext>
#include <QScriptEngine>

QScriptProgram AIScript::read(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly|QFile::Text)) return QScriptProgram();
    return QScriptProgram(file.readAll(), fileName);
}

bool AIScript::evaluate(const QScriptProgram &program, QScriptEngine *engine) {
  QScriptContext *context = engine->pushContext();
  QScriptValue activationObject;
  QScriptValue result = engine->evaluate(program);
  activationObject = context->activationObject();
  if(!result.isError()) {
    initFunction = activationObject.property("init");
    heartbeatFunction = activationObject.property("heartbeat");
    defendFunction = activationObject.property("defend");
  }
  engine->popContext();
  return !result.isError();
}
