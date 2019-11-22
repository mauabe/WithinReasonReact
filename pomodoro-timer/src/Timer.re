type state = {
  seconds: int,
  isTicking: bool
};

type action =
  | Start
  | Stop
  | Reset
  | Tick;


[@react.component]
let make = () => {
   React.useReducer(
      (state, action) =>
        switch (action) {
        | Start => {...state, isTicking: true}
        | Stop => {...state, isTicking: false}
        | Reset => {...state, seconds: 30}
        | Tick => state.isTicking && state.seconds > 0
            ? {...state, seconds: state.seconds - 1} : state
        },
      {isTicking: false, seconds: 30},
    );

  <div>
    {ReasonReact.string(
       "There are " ++ string_of_int(state.seconds) ++ " on the clock",
     )}
  </div>;
};

React.useEffect0(() => {
  let timerId = Js.Global.setInterval(() => dispatch(Tick), 1000);
  Some(() => Js.Global.clearInterval(timerId));
});

module Button = {
  [@react.component]
  let make = (~label, ~onClick) => {
    <button onClick> {label |> ReasonReact.string} </button>;
  };
};

