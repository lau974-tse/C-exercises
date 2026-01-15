namespace hellmath {

// Task 1
enum class AccountStatus {
    troll,
    guest,
    user,
    mod
};

enum class Action {
    read,
    write,
    remove
};

// Task 2
bool display_post(AccountStatus poster, AccountStatus viewer)
{
    if (poster == AccountStatus::troll) {
        return viewer == AccountStatus::troll;
    }
    return true;
}

// Task 3
bool permission_check(Action action, AccountStatus status)
{
    switch (status) {
        case AccountStatus::guest:
            return action == Action::read;

        case AccountStatus::user:
        case AccountStatus::troll:
            return action == Action::read || action == Action::write;

        case AccountStatus::mod:
            return true;
    }
    return false; // sécurité
}

// Task 4
bool valid_player_combination(AccountStatus player1, AccountStatus player2)
{
    if (player1 == AccountStatus::guest || player2 == AccountStatus::guest) {
        return false;
    }
    if (player1 == AccountStatus::troll || player2 == AccountStatus::troll) {
        return player1 == AccountStatus::troll &&
               player2 == AccountStatus::troll;
    }
    return true;
}

// Task 5
bool has_priority(AccountStatus player1, AccountStatus player2)
{
    if (player1 == AccountStatus::mod && player2 != AccountStatus::mod) {
        return true;
    }

    if (player1 == AccountStatus::user &&
        (player2 == AccountStatus::guest || player2 == AccountStatus::troll)) {
        return true;
    }

    if (player1 == AccountStatus::guest && player2 == AccountStatus::troll) {
        return true;
    }

    return false;
}

}  // namespace hellmath
