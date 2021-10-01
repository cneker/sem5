using System;

namespace lab03 {
    class EmptyException : Exception {
        public override string Message => "Не достаточно элементов";
    }

    class UnknownCommandExceprion : Exception {
        public override string Message => "Данной команды не существует";
    }

    class DefineException : Exception {
        public override string Message => "Такого параметра нема";
    }

    class DefineExistExceprion : Exception {
        public override string Message => "Такой параметр уже есть";
    }
}