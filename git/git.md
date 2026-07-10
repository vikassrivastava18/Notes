# Git concepts and commands.

## Code in Git exists in three areas:
- **Working directory** - The local development playground where you create, modify, or delete files before staging them..
- **Staging** - This is a virtual space where you put your code before commit. A git add *file_name* or ./-A command is used for staging the file/all files.
- **Git directory** - Stores commits, branches, and metadata.
  Git tracks content internally using SHA-1 hashes.

### Git status
 Helps in tracking what is in the working directory, staging area, and repository.
```
On branch master
Your branch is up to date with 'origin/master'.

Changes to be committed:
  (use "git restore --staged <file>..." to unstage)
        modified:   readme.md

Changes not staged for commit:
  (use "git add/rm <file>..." to update what will be committed)
  (use "git restore <file>..." to discard changes in working directory)
        deleted:    bad.md
```
The above output suggests that file readme.md has been staged, but not committed and file bad.md has been deleted but not yet staged.


## Fix changes made in a commit before pushing to remote.
- ```git commit --amend -m "comment"```: Change comment in the last commit.
- ```git commit --amend --no-edit```: Change previous commit, by adding/updating/removing files you forgot in latest commit.


## A new commit is bad, but we need to track it still.
``` git revert {hash}```: This creates a new commit that reverses the changes made in last commit. Recommended to not lose of previous commits.


## A new commit is too bad, remove it!

-  ```git reset --hard HEAD~1```: Just forget the latest commit and move back to previous one. > ⚠️ Dangerous if already pushed.

- ```git reset --hard {hash}```: Removes all commits after the specified hash from the current branch history.
⚠️ Dangerous if already pushed.

- ```git reset --mixed HEAD~1```: The committed code in latest commit goes to the working directory, stage whatever you feel necessary. 

- ```git reset --soft HEAD~1```: The committed code in latest commit goes to the staging area along with the previous commit code.


## Restore a file to previous commit
- ``` git restore --source=HEAD~1 filename```: The file is changed to previous commit state.
- ``` git restore filename```: This discards uncommitted changes in the working directory and restores the file to the last committed state.


## Stash
- ```git stash push -m "name"```: Stash the working directory changes, could be brought back later to working directory
- ``` git stash list```: List all the saved stashes.
- `git stash pop` – Applies and removes the latest stash.
- `git stash apply stash@{0}` – Applies a specific stash without removing it.


## Most used commands
- **Git status** - Shows the state of the working directory and staging area, and whether your branch is ahead/behind the remote.
- **Git log --oneline -n 5** - Show one liners log of 5 previous git commit history.

## Rebase
``` git rebase {branch_name}```: Reapplies your branch commits on top of another branch.
It rewrites commit history by creating new commit hashes.
⚠️ Avoid rebasing shared branches.