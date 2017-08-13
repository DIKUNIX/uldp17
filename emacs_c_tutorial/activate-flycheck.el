;; on the fly syntax check
(require 'flycheck)
(global-flycheck-mode)

;; package to show flycheck error after jumping to point (OPTIONAL)
(require 'flycheck-tip)
(flycheck-tip)
