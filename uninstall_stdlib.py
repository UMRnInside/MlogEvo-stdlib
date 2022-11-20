import os
import sysconfig
import shutil

def get_include_path() -> str:
    if os.name == "posix":
        return sysconfig.get_path("include", "posix_user")
    elif os.name == "nt":
        return sysconfig.get_path("include", "nt")
    raise ValueError(f"Cannot determine include path on OS `{os.name}`, consider manual installation.")

if __name__ == "__main__":
    include_path = get_include_path()
    target = os.path.join(include_path, "mlogevo")
    print("Uninstalling MlogEvo standard library")
    print(f"target: {target}")
    shutil.rmtree(target)
    print("Uninstallation complete!")
